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
            long long N;
            cin>>N;
            long long a=1;
            long long b=1;
            for(int i=0;i<=40;i++){
                if(i>0)
                    a=a*3LL;
                b=1;
                for(int j=0;j<=30;j++){
                    if(j>0)
                        b=b*5LL;
                    if(a+b==N){
                        cout<<i<<" "<<j;
                        return;
                    }
                    if(b>(b*5LL))
                        break;
 
                }
                if(a>(a*3LL))
                    break;
            }
            cout<<-1;
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
