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
            if(n==0){
                cout<<0;
                return;
            }
            string s="";
            while(n!=1){
                if(n>1){
                    int k=n%2;
                    s=s+(char)('0'+k);
                    n=(n/2)*(-1);
                }
                else{
                    int k=(abs(n))%2;
                    s+=(char)('0'+k);
                    n=abs(n);
                    if(n%2)
                        n=(n/2)+1;
                    else 
                        n=n/2;
                }
            }
            s.push_back('1');
            reverse(s.begin(),s.end());
            cout<<s;
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
