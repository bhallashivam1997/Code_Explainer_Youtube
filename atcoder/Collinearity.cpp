#include <bits/stdc++.h>
        #include <math.h>
    
        using namespace std;
        typedef long long ll;
        typedef unsigned long long ull;
        # define M_PI  3.14159265358979323846
    
    
        const int M=998244353;
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
            vector<pair<int,int>>a(n);
            for(int i=0;i<n;i++){
                int x,y;
                cin>>x>>y;
                a[i]={x,y};
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        int x1=a[j].first-a[i].first;
                        int y1=a[j].second-a[i].second;
                        int x2=a[k].first-a[i].first;
                        int y2=a[k].second-a[i].second;
                        if(x1*y2 == x2*y1){
                            // cout<<i<<" "<<j<<" "<<k<<"\n";
                            cout<<"Yes";
                            return;
                        }
                    }
                }
            }
            cout<<"No";
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
