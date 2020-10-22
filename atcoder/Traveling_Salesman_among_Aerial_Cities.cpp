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
 
        int n;
        long long dp[20][1<<18];
        long long a[20][3];
 
        long long d(int i , int j){
            return abs(a[j][0]-a[i][0])+abs(a[j][1]-a[i][1])+max(0LL,a[j][2]-a[i][2]);
        }
 
        long long ok(int i , int mask){
            if(dp[i][mask]!=-1)
                return dp[i][mask];
            if(mask==0) return d(i,0);
            long long ans=(1e18);
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    ans=min(ans,d(i,j)+ok(j,mask^(1<<j)));
                }
            }
            return dp[i][mask]=ans;
        }
        
        void solve (){
            memset(dp,-1,sizeof(dp));
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a[i][0]>>a[i][1]>>a[i][2];
            }
            cout<<ok(0,(1<<n)-2)<<"\n";
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
