// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1;
        long long r=n;
        while(l<r){
            long long mid=((long long)l+r)/2;
            if(isBadVersion(mid))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
