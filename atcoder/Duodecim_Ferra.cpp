#include <bits/stdc++.h>
        #include <math.h>
    
        using namespace std;
        typedef long long ll;
        typedef unsigned long long ull;
        # define M_PI  3.14159265358979323846
    
    
        // const int M=1e9+7;
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
        ll dp[500][500];
 
        ll ok(ll i, ll n ,ll cuts){
            if(i>n) return 0;
            if(cuts==0) return 1;
            if(dp[i][cuts]!=-1) return dp[i][cuts];
            ll ans=0;
            for(int j=i+1;j<n;j++){
                ans+=ok(j,n,cuts-1);
            }
            return dp[i][cuts]=ans;
        }
 
        void solve(){
            memset(dp,-1,sizeof(dp));
            ll n;
            cin>>n;
            ll ans=ok(0LL,n,11LL);
            cout<<ans;
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
