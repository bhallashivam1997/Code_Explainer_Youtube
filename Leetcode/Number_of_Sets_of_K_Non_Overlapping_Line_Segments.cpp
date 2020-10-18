class Solution {
public:
    const int M=1e9+7;
    int mod(int a){
        return (a%M + M)%M;
    }
    int add(int a, int b){
        return mod(mod(a)+mod(b));
    }
    int mul(int a, int b){
        return mod(mod(a)*mod(b));
    }
    
    int dp[1002][1002];
    int prefDp[1002][1002];
    
    int prefOk(int n, int k){
        if(n<2)
            return 0;
        if(prefDp[n][k]!=-1)
            return prefDp[n][k];
        return prefDp[n][k]=add(prefOk(n-1,k),ok(n,k));
    }
    
    int ok(int n , int k){
        if(k==1){ // only one seg to make
            return dp[n][k]=(n*(n-1))/2;
        }
        if(n==1) // only one point
            return 0;
        if(n-1==k) // all segments of lenght 1
            return 1;
        if(n-1<k)
            return 0;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int total=0;
        total=add(total,ok(n-1,k));
        // for(int i=1;i<n;i++){
        //     total=add(total,ok(n-i,k-1));
        // }
        total=add(total,prefOk(n-1,k-1));
        return dp[n][k]=total;
    }
    
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        memset(prefDp,-1,sizeof(prefDp));
        return ok(n,k);
    }
};
