class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int l=0;
        // int r=nums.size()-1;
        // while(l<r){
        //     int mid=(l+r)/2;
        //     if(nums[mid]==target)
        //         return mid;
        //     else if(nums[mid]>target)
        //         r=mid-1;
        //     else
        //         l=mid+1;
        // }
        // if(nums[l]==target)
        //     return l;
        // return -1;
        int index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(index==nums.size())
            return -1;
        if(nums[index]==target)
            return index;
        return -1;
    }
};
