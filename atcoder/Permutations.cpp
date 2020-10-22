class Solution {
public:
    vector<vector<int>>ans;
    vector<int>a;
    void ok(int mask , vector<int>& nums){
        int n=nums.size();
        if(mask==0 && (int)a.size()){
            ans.push_back(a);
            return;
        }
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                a.push_back(nums[j]);
                ok(mask^(1<<j),nums);
                a.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        int mask=(1<<(n))-1;
        ok(mask,nums);
        return ans;
    }
};
