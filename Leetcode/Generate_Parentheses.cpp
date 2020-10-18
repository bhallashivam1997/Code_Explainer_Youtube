class Solution {
public:
    vector<string>ans;
    
    void ok(string curr , int score, int& len){
        if(score<0)
            return;
        if((int)curr.size()>(2*len))
            return;
        if((int)curr.size()==(2*len) && score==0)
            ans.push_back(curr);
        ok(curr+"(" , score+1 ,len);
        ok(curr+")" , score-1 ,len);
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string curr="";
        ok(curr,0,n);
        return ans;
    }
};
