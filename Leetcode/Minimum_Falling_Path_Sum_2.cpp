class Solution {
public:
    
    int dp[205][205];
    int ok(vector<vector<int>>& arr , int r, int c){
        int n=arr.size();
        if(r==n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            if(i!=c) ans=min(ans,ok(arr,r+1,i));
        }
        return dp[r][c]=ans+arr[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,ok(arr,0,i));
        return ans;
    }
};
