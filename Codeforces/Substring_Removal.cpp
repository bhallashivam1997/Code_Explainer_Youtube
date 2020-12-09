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
            int n;
            cin>>n;
            string s;
            cin>>s;
            if(n==1){
                cout<<1<<"\n";
                return;
            }
            // whole string is same
            bool flag=true;
            for(int i=1;i<n;i++){
                if(s[i]!=s[i-1]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                long long one=n;
                long long two=n+1;
                if(n%2==0)
                    one/=2;
                else 
                    two/=2;
                long long ans=mul(one,two);
                cout<<ans<<"\n";
                return;
            }
            int left=1;
            for(int i=1;i<n;i++){
                if(s[i]==s[i-1])
                    left++;
                else 
                    break;
            }
            int right=1;
            for(int i=n-2;i>=0;i--){
                if(s[i]==s[i+1])
                    right++;
                else 
                    break;
            }
            long long ans=0;
            if(s[0]==s[n-1]){
                ans=mul(left,right);
            }
            ans=add(ans,left);
            ans=add(ans,right);
            ans=add(ans,1);
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
