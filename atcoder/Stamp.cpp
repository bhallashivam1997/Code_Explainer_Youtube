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
            vector<int>a(m);
            for(int i=0;i<m;i++){
                cin>>a[i];
            }
            if(m==0){
                cout<<1;
                return;
            }
            sort(a.begin(),a.end());
            ll ans=-1;
            ll k;
            if(m){
                k=a[0]-1;
                if(k)
                    ans=k;
                k=n-a[m-1];
                if(ans==-1 && k)
                    ans=k;
                 else if(k)
                    ans=min(ans,k);
            }
            // cout<<"ininin "<<ans<<"\n";
            for(int i=1;i<m;i++){
                ll diff=a[i]-a[i-1]-1;
                if(ans==-1 && diff)
                    ans=diff;
                else if(diff)
                    ans=min(ans,diff);
            }
            // cout<<"in "<<ans<<"\n";
            ll ok=0;
            if(m){
                k=a[0]-1;
                ok+=k/ans;
                if(k%ans) ok++;
                k=n-a[m-1];
                ok+=k/ans;
                if(k%ans) ok++;
            }
            for(int i=1;i<m;i++){
                int diff=a[i]-a[i-1]-1;
                ok+=diff/ans;
                if(diff%ans) ok++;
            }
            cout<<ok;
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
