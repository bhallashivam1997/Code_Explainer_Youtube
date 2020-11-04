class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        int total=0;
        int start=n-1;
        for(int i=n-1;i>=0;i--){
            total+=sat[i];
            if(total<0){
                break;
            }
            start--;
        }
        start++;
        int k=1;
        total=0;
        for(int i=start;i<n;i++){
            total+=(k++)*(sat[i]);
        }
        return total;
    }
};
