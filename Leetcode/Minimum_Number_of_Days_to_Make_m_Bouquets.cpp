class Solution {
public:
    
    bool ok(long long mid , vector<int>& A , int& m , int& k){
        int sub_array=0;
        int total=0;
        int n=A.size();
        for(int i=0;i<n;i++){
            if(A[i]<=mid)
                total++;
            else{
                if(total>=k){
                    sub_array++;
                }
                total=0;
            }
            if(total>=k){
                sub_array++;
                total=0;
            }
        }
        if(total>=k)
            sub_array++;
        return (sub_array>=m);
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*k > (long long)bloomDay.size())
            return -1;
        while(l<r){
            long long mid=((long long)l+r)/2;
            if(ok(mid,bloomDay,m,k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
