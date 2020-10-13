class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n=J.size();
        int m=S.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[J[i]]=1;
        }
        int total=0;
        for(int i=0;i<m;i++){
            total+=mp[S[i]];
        }
        return total;
    }
};
