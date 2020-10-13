class Solution {
public:
    
    bool ok(int mid , vector<int>& a , int& k){
        int n=a.size();
        int j=1;
        int total=0;
        for(int i=0;i<n;i++){
            while(j<n && a[j]-a[i]<=mid) j++;
            j--;
            int x=(j-i);
            total+=x;
        }
        return (total>=k);
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=nums[n-1]-nums[0];
        int l=0;
        int r=diff;
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,nums,k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
