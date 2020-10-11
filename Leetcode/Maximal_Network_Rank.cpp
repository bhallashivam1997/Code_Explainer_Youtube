class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxi=0;
        vector<int>adj[102];
        for(int i=0;i<(int)roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int total=0;
                int ok=0;
                for(int k=0;k<(int)adj[i].size();k++){
                    if(adj[i][k]==j)
                        ok=1;
                }
                total=(int)adj[i].size() + (int)adj[j].size();
                if(ok)
                    total--;
                maxi=max(maxi,total);
            }
        }
        return maxi;
    }
};
