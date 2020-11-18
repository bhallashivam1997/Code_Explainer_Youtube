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
 
        void ok4(vector<vector<int>>&b , vector<string>& a , int i , int j){
            a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0';
            vector<int>c;
            c.push_back(i);
            c.push_back(j);
            c.push_back(i+1);
            c.push_back(j);
            c.push_back(i+1);
            c.push_back(j+1);
            b.push_back(c);
            c.clear();
            c.push_back(i);
            c.push_back(j+1);
            c.push_back(i+1);
            c.push_back(j);
            c.push_back(i+1);
            c.push_back(j+1);
            b.push_back(c);
            c.clear();
            c.push_back(i);
            c.push_back(j);
            c.push_back(i);
            c.push_back(j+1);
            c.push_back(i+1);
            c.push_back(j);
            b.push_back(c);
            c.clear();
            c.push_back(i);
            c.push_back(j);
            c.push_back(i);
            c.push_back(j+1);
            c.push_back(i+1);
            c.push_back(j+1);
            b.push_back(c);
        }
 
        void ok1(vector<vector<int>>&b , vector<string>& a , int i , int j){
            vector<int>c;
            if(a[i][j]=='1'){
                c.push_back(i);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j+1);
                b.push_back(c);
            }
            if(a[i][j+1]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j+1);
                b.push_back(c);
            }
            if(a[i+1][j]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j+1);
                b.push_back(c);
            }
            if(a[i+1][j+1]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i);
                c.push_back(j+1);
                b.push_back(c);
            }
        }
 
        void ok2(vector<vector<int>>&b , vector<string>& a , int i , int j){
            // cout<<"in "<<"\n";
            vector<int>c;
            if(a[i][j]=='1' && a[i][j+1]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j+1);
                b.push_back(c);
                a[i][j]=a[i][j+1]='0';
                a[i+1][j+1]='1';
            }
            if(a[i][j]=='1' && a[i+1][j]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j+1);
                b.push_back(c);
                a[i][j]=a[i+1][j]='0';
                a[i+1][j+1]='1';
            }
            if(a[i][j]=='1' && a[i+1][j+1]=='1'){
                c.push_back(i);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j);
                b.push_back(c);
                a[i][j]=a[i+1][j+1]='0';
                a[i+1][j]='1';
            }
            if(a[i][j+1]=='1' && a[i+1][j]=='1'){
                c.push_back(i);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i);
                c.push_back(j);
                b.push_back(c);
                a[i][j+1]=a[i+1][j]='0';
                a[i][j]='1';
            }
            if(a[i][j+1]=='1' && a[i+1][j+1]=='1'){
                c.push_back(i);
                c.push_back(j+1);
                c.push_back(i+1);
                c.push_back(j+1);
                c.push_back(i);
                c.push_back(j);
                b.push_back(c);
                a[i][j+1]=a[i+1][j+1]='0';
                a[i][j]='1';
            }
            if(a[i+1][j]=='1' && a[i+1][j+1]=='1'){
                c.push_back(i+1);
                c.push_back(j);
                c.push_back(i+1);
                c.push_back(j+1);
                c.push_back(i);
                c.push_back(j);
                b.push_back(c);
                a[i+1][j]=a[i+1][j+1]='0';
                a[i][j]='1';
            }
        }
 
        void solve(){
            int n,m;
            cin>>n>>m;
            vector<string>a(n);
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            vector<vector<int>>b;
            for(int i=0;i<n-1;i++){
                for(int j=0;j<m-1;j++){
                    int total=0;
                    total=(a[i][j]-'0')+(a[i][j+1]-'0')+(a[i+1][j]-'0')+(a[i+1][j+1]-'0');
                    if(total==0)
                        continue;
                    else if(total==3){
                        vector<int>c;
                        if(a[i][j]=='1'){
                            a[i][j]='0';
                            c.push_back(i);
                            c.push_back(j);
                        }
                        if(a[i][j+1]=='1'){
                            a[i][j+1]='0';
                            c.push_back(i);
                            c.push_back(j+1);
                        }
                        if(a[i+1][j]=='1'){
                            a[i+1][j]='0';
                            c.push_back(i+1);
                            c.push_back(j);
                        }
                        if(a[i+1][j+1]=='1'){
                            a[i+1][j+1]='0';
                            c.push_back(i+1);
                            c.push_back(j+1);
                        }
                        b.push_back(c);
                    }
                    else if(total==4){
                        ok4(b,a,i,j);
                    }
                    else if(total==1){
                        ok1(b,a,i,j);
                        ok4(b,a,i,j);
                    }
                    else{
                        ok2(b,a,i,j);
                        ok1(b,a,i,j);
                        ok4(b,a,i,j);
                    }
                }
            }
            cout<<(int)b.size()<<"\n";
            for(int i=0;i<(int)b.size();i++){
                for(int j=0;j<6;j++)
                    cout<<b[i][j]+1<<" ";
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
