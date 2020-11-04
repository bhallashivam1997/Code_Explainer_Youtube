class Solution {
public:
    
    int vis[105][105];
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
    void ok(int x, int y,int mid , vector<vector<int>>& heights){
        if(!vis[x][y]){
            vis[x][y]=1;
            int n=heights.size();
            int m=heights[0].size();
            for(int i=0;i<4;i++){
                int X=x+dir[i].first;
                int Y=y+dir[i].second;
                if(X<0 || X>=n || Y<0 || Y>=m)
                    continue;
                if(abs(heights[x][y]-heights[X][Y])<=mid)
                    ok(X,Y,mid,heights);
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0,r=1e9+2;
        int n=heights.size();
        int m=heights[0].size();
        while(l<r){
            int mid=(l+r)/2;
            memset(vis,0,sizeof(vis));
            ok(0,0,mid,heights);
            if(vis[n-1][m-1]==1)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
