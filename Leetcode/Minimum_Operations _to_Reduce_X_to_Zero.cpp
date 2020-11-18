class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total=0;
        for(auto i : nums)
            total+=i;
        if(total<x) return -1;
        if(total==x) return (nums.size());
        int n=nums.size();
        vector<long long>pref(n+1);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int ans=1e9;
        long long other=0;
        for(int i=n;i>=0;i--){
            if(i!=n)
                other+=nums[i];
            long long left=x-other;
            int y=lower_bound(pref.begin(),pref.end(),left)-pref.begin();
            if(y<nums.size() && pref[y]==left && y<i)
                ans=min(ans,y+(n-i));
        }
        return (ans==1e9 ? -1 : ans);   
    }
};
