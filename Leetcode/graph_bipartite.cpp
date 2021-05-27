class Solution {
public:
    
    int color[105];
    int vis[105];
    bool dfs(vector<vector<int>>& graph, int i , int c){
        vis[i]=1;
        color[i]=c;
        for(auto j : graph[i]){
            if(vis[j]==0){
                if(dfs(graph,j,c^1)==false) return false;
            }
            else{
                if(color[i]==color[j]) return false;
            }
        }
        return true;-
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        // using graph coloring algorithm
        int n = graph.size();
        for(int i=0;i<n;i++){
            if(color[i]==0 && dfs(graph,i,0)==false) return false;
        }
        return true;
    }
};
