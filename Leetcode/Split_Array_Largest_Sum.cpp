class Solution {
public:
    
    bool ok(int mid , vector<int>& nums , int m){
        int total=0;
        int sub_array=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mid)
                return false;
            if(total+nums[i]<=mid)
                total+=nums[i];
            else{
                sub_array++;
                total=nums[i];
            }
        }
        sub_array++;
        return (sub_array<=m);
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        int r=(int)(1e9+1);
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,nums,m))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
