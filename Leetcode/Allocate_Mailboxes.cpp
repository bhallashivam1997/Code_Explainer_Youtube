class Solution {
public:
    int cost[101][101];
    int dp[101][101];
    
    int ok(vector<int>& houses , int k , int start){
        int n=houses.size();
        if(k==0 && start==n) return 0;
        if(k==0 || start==n) return 1e7;
        if(dp[k][start]!=-1) return dp[k][start];
        int ans=1e7;
        for(int i=start;i<n;i++){
            ans=min(ans,cost[start][i]+ok(houses,k-1,i+1));
        }
        return dp[k][start]=ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n=houses.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int x=i;x<=j;x++){
                    cost[i][j]+=abs(houses[(i+j)/2]-houses[x]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return ok(houses,k,0);
    }
};
