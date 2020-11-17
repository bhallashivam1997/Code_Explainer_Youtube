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
            int n,c0,c1,h;
            string s;
            cin>>n>>c0>>c1>>h>>s;
            int zero=0,one=0;
            for(int i=0;i<n;i++){
                if(s[i]=='0')
                    zero++;
                else 
                    one++;
            }
            int ans=(zero*c0)+(one*c1);
            for(int i=1;i<=zero;i++){
                int other=(i*h)+((one+i)*c1)+((zero-i)*c0);
                ans=min(ans,other);
            }
            for(int i=1;i<=one;i++){
                int other=(i*h)+((zero+i)*c0)+((one-i)*c1);
                ans=min(ans,other);
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
