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


        void solve(){
            int n;
            cin>>n;
            vector<string>s(n);
            for(int i=0;i<n;i++)
                cin>>s[i];
            vector<int>ans(10,0);
            vector<int>minir(10,n);
            vector<int>minic(10,n);
            vector<int>maxir(10,-1);
            vector<int>maxic(10,-1);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int num=s[i][j]-'0';
                    minir[num]=min(minir[num],i);
                    maxir[num]=max(maxir[num],i);
                    minic[num]=min(minic[num],j);
                    maxic[num]=max(maxic[num],j);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int num=(int)s[i][j]-'0';
                    ans[num]=max(ans[num],max(maxir[num]-i,i-minir[num])*max(n-j-1,j));
                    ans[num]=max(ans[num],max(maxic[num]-j,j-minic[num])*max(n-i-1,i));
                }
            }
            for(auto i : ans)
                cout<<i<<" ";
            cout<<"\n";
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
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";
                solve();
            }
            return 0;
        }
