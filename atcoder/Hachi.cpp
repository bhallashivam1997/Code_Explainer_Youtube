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
            string s;
            cin>>s;
            vector<int>mp(10,0);
            int n=s.size();
            for(int i=0;i<n;i++){
                mp[s[i]-'0']++;
            }
            if(n==1){
                if(s[0]=='8'){
                    cout<<"Yes";
                }
                else{
                    cout<<"No";
                }
                return;
            }
            if(n==2){
                if(((s[0]-'0')*10 + (s[1]-'0'))%8==0 || ((s[1]-'0')*10 + (s[0]-'0'))%8==0){
                    cout<<"Yes";
                }
                else{
                    cout<<"No";
                }
                return;
            }
            if(mp[0]>=3){
                cout<<"Yes";
                return;
            }
            for(int i=104;i<1000;i+=8){
                vector<int>mp2(10);
                int x=i;
                while(x){
                    int k=x%10;
                    mp2[k]++;
                    x=x/10;
                }
                bool flag=false;
                for(int j=0;j<10;j++){
                    if(mp[j]<mp2[j]){
                        flag=true;
                    }
                }
                if(!flag){
                    cout<<"Yes";
                    return;
                }
            }
            cout<<"No";
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
