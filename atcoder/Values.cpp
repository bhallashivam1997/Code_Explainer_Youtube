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
        vector<int>adj[200005];
        vector<bool>vis(200005,false);
        vector<int>a(200005);
        vector<int>b(200005);
        long long suma=0;
        long long sumb=0;
 
        void dfs(int i){
            if(!vis[i]){
                vis[i]=true;
                suma+=(long long)a[i];
                sumb+=(long long)b[i];
                for(auto v : adj[i]){
                    dfs(v);
                }
            }
        }
 
 
        void solve (){  
            int n,m;
            cin>>n>>m;
            for(int i=0;i<n;i++)
                cin>>a[i];
            for(int i=0;i<n;i++)
                cin>>b[i];
            for(int i=0;i<m;i++){
                int x,y;
                cin>>x>>y;
                --x;
                --y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    suma=0;
                    sumb=0;
                    dfs(i);
                    if(suma!=sumb){
                        cout<<"No";
                        return;
                    }
                }
            }
            cout<<"Yes";
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
