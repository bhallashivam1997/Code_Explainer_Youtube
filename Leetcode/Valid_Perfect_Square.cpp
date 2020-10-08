class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int r=(1<<31 - 1);
        while(l<r){
            int mid=(l+r)/2;
            long long ans=(long long)mid*mid;
            if(ans==(long long)num)
                return true;
            else if(ans>(long long)num)
                r=mid-1;
            else
                l=mid+1;
        }
        if((long long)l*l == (long long)num)
            return true;
        return false;
    }
};
