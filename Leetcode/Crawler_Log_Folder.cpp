class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int total=0;
        for(int i=0;i<n;i++){
            if(logs[i][0]=='.' && logs[i][1]=='.')
                total=max(0,--total);
            else if(logs[i][0]=='.')
                continue;
            else
                total++;
        }
        return total;
    }
};
