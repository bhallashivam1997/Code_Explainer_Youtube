class Solution {
public:
    
    bool ok(int mid , vector<int>& piles , int H){
        int n=piles.size();
        int total=0;
        for(int i=0;i<n;i++){
            int x=piles[i]/mid;
            int y=piles[i]%mid;
            if(y)
                x++;
            total+=x;
        }
        return (total<=H);
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int l=1;
        int r=(int)(1e9+1);
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,piles,H))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
