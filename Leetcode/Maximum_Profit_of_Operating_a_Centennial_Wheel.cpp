class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n=customers.size();
        int maxi=-1;
        int total=0;
        int turns=0;
        int val;
        int maxi_turn;
        int total_people=0;
        for(int i=0;i<n;i++){
            total_people+=customers[i];
            turns++;
            if(total_people>=4){
                total+=4;
                total_people-=4;
            }
            else{
                total+=total_people;
                total_people=0;
            }
            val=(total*boardingCost)-(turns*runningCost);
            if(val>maxi){
                maxi=val;
                maxi_turn=turns;
            }
        }
        // cout<<total_people<<"\n";
        while(total_people){
            turns++;
            if(total_people>=4){
                total+=4;
                total_people-=4;
            }
            else{
                total+=total_people;
                total_people=0;
            }
            val=(total*boardingCost)-(turns*runningCost);
            if(val>maxi){
                maxi=val;
                maxi_turn=turns;
            }
        }
        return (maxi>=0 ? maxi_turn : -1);
    }
};
