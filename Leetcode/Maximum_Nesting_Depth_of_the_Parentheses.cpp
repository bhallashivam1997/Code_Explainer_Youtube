class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int dep=0;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='(')
                dep++;
            else if(s[i]==')')
                dep--;
            maxi=max(maxi,dep);
        }
        return maxi;
    }
};
