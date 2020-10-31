class Solution {
public:
    
    static bool f(pair<int,int>& a, pair<int,int>&b){
        if(a.first==b.first)
            return (a.second>b.second);
        return (a.first<b.first);
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>a(201);
        for(int i=0;i<=200;i++){
            a[i].first=0;
            a[i].second=i;
        }
        for(int i=0;i<(int)nums.size();i++){
            a[nums[i]+100].first++;
        }
        vector<int>ans;
        sort(a.begin(),a.end(),f);
        for(int i=0;i<=200;i++){
            if(a[i].first){
                for(int j=0;j<a[i].first;j++){
                    ans.push_back(a[i].second-100);
                }
            }
        }
        return ans;
    }
};
