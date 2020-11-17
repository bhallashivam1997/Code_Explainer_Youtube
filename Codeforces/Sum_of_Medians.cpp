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
            int n,k;
            cin>>n>>k;
            int m=n*k;
            vector<int>a(m);
            for(int i=0;i<m;i++)
                cin>>a[i];
            ll total=0;
            if(n==2){
                for(int i=0;i<m;i+=2)
                    total+=(ll)(a[i]);
                cout<<total<<"\n";
                return;
            }
            int interval=(n+1)/2;
            int left=n-interval;
            left++;
            int x=1;
            int in=0;
            for(int i=m-1;i>=0;i--){
                if(x%left==0){
                    total+=a[i];
                    in++;
                }
                x++;
                if(in>=k)
                    break;
            }
            cout<<total<<"\n";
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
