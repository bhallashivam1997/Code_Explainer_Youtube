class Solution {
public:
    
    vector<vector<int>>vis;
    int N,M;
    void ok(int mid,int x, int y,vector<vector<int>>& grid){
        if(!vis[x][y] && grid[x][y]<=mid){
            vis[x][y]=1;
            if(x-1>=0) ok(mid,x-1,y,grid);
            if(x+1<N) ok(mid,x+1,y,grid);
            if(y-1>=0) ok(mid,x,y-1,grid);
            if(y+1<M) ok(mid,x,y+1,grid);
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int l=0;
        int r=50*50;
        int n=grid.size();
        int m=grid[0].size();
        N=n;
        M=m;
        while(l<r){
            int mid=(l+r)/2;
            vis=vector<vector<int>>(n,vector<int>(m,0));
            ok(mid,0,0,grid);
            if(vis[n-1][m-1])
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
