class Solution {
public:
    
    bool ok(int mid , vector<int>& weights , int D){
        int n=weights.size();
        int days=1;
        int total=0;
        bool isValid=true;
        for(int i=0;i<n;i++){
            if(weights[i]>mid)
                isValid=false;
            if(total+weights[i]<=mid)
                total+=weights[i];
            else{
                days++;
                total=weights[i];
            }
        }
        if(!isValid)
            return false;
        else
            return (days<=D);
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int l=1;
        int r=50000*500;
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,weights,D))
                r=mid;
            else
                l=mid+1;
            // cout<<"in "<<l<<" "<<r<<"\n";
        }
        return l;
    }
};
