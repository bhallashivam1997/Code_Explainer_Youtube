class ThroneInheritance {
public:
    unordered_map<string,int>a;
    unordered_map<int,string>b;
    vector<int>vec[100005];
    int total=0;
    int dead[100005];
    ThroneInheritance(string kingName) {
        total++;
        a[kingName]=total;
        b[total]=kingName;
    }
    
    void birth(string parentName, string childName) {
        total++;
        a[childName]=total;
        b[total]=childName;
        vec[a[parentName]].push_back(a[childName]);
    }
    
    void death(string name) {
        dead[a[name]]=1;
    }
    
    vecWeekly Contest 208
tor<string>ans;
    void dfs(int u){
        if(dead[u]==0)
            ans.push_back(b[u]);
        for(int v=0;v<(int)vec[u].size();v++)
            dfs(vec[u][v]);
    }
    
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(1);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
