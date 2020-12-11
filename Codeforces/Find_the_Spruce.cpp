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

        void solve(){
            int n,m;
            cin>>n>>m;
            vector<string>s(n);
            for(int i=0;i<n;i++)
                cin>>s[i];
            vector<vector<int>>dp(n+1,vector<int>(m+1));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(s[i][j]=='*')
                        dp[i][j]=1;
                }
            }
            int ans=0;
            for(int i=n-1;i>=0;i--){
                for(int j=m-2;j>=1;j--){
                    if(dp[i][j]==1){
                        dp[i][j]=1+min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    ans+=dp[i][j];
            }
            cout<<ans<<"\n";
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
