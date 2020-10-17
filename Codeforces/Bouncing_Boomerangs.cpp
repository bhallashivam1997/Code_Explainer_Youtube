#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }
 
    void solve (){
        int n;
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vector<pair<int,int>>ans;
        vector<int>ones,two,three;
        vector<int>twoMatch(100005,0),threeMatch(100005,0),col(100005,0);
        for(int i=n;i>=1;i--){
            if(a[i]==1){
                ones.push_back(i);
            }
            else if(a[i]==2){
                if(ones.size()==0){
                    cout<<-1;
                    return;
                }
                else{
                    twoMatch[i]=ones.back();
                    ones.pop_back();
                }
                two.push_back(i);
            }
            else if(a[i]==3){
                if(three.size()>0)
                    threeMatch[i]=three.back();
                else if(two.size()>0){
                    threeMatch[i]=two.back();
                }
                else if(ones.size()>0){
                    threeMatch[i]=ones.back();
                    ones.pop_back();
                }
                else{
                    cout<<-1;
                    return;
                }
                three.push_back(i);
            }
        }
        int row=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0 || col[i]==1)
                continue;
            int cur=i;
            while(cur!=0){
                col[cur]=1;
                if(a[cur]==1){
                    ans.push_back({row,cur});
                    cur=0;
                    row++;
                }
                else if(a[cur]==2){
                    ans.push_back({row,cur});
                    cur=twoMatch[cur];
                }
                else{
                    ans.push_back({row,cur});
                    cur=threeMatch[cur];
                    ans.push_back({row,cur});
                    row++;
                }
            }
        }
        cout<<(int)ans.size()<<"\n";
        for(auto i : ans)
            cout<<i.first<<" "<<i.second<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        // cin>>t;
        for(int i=1;i<=t;i++){
        //    cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }
