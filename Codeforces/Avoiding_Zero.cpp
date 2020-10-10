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
        int n;
        cin>>n;
        vector<ll>a(n);
        ll total=0;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            total+=x;
            a[i]=x;
        }
        sort(a.begin(),a.end());
        if(total==0){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
            ll sum=0;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==0)
                    swap(a[i],a[n-1]);
            }
            sum=0;
            int ok=1;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==0)
                    ok=0;
            }
            if(ok){
                for(int i=0;i<n;i++)
                    cout<<a[i]<<" ";
                cout<<"\n";
                return;
            }
            sort(a.begin(),a.end(),greater<>());
            sum=0;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==0)
                    swap(a[i],a[n-1]);
            }
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
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
