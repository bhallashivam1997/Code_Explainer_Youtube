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
 
        int check(vector<int>&a , int k){
            int total=0;
            int n=a.size();
            int sum=0;
            int j=0;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==k){
                    total+=(i-j);
                    j=i+1;
                    sum=0;
                }
                else if(sum>k){
                    return -1;
                }
            }
            return total;
        }
       
        void solve(){
            int n;
            cin>>n;
            vector<int>a(n);
            int total=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                total+=a[i];
            }
            int ans=n-1;
            for(int i=1;i*i<=total;i++){
                if(total%i==0){
                    int f1=i;
                    int f2=total/i;
                    int a1=check(a,f1);
                    int a2=check(a,f2);
                    // cout<<f1<<" "<<a1<<"\n";
                    // cout<<f2<<" "<<a2<<"\n";
                    if(a1!=-1)
                        ans=min(ans,a1);
                    if(a2!=-1)
                        ans=min(ans,a2);
                }
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
            // g();
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";
                solve();
            }
            return 0;
        }
