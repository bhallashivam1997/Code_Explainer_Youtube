class Solution {
public:
    vector<string>ans;
    
    void ok(string& S ,string curr , int index){
        if((int)curr.size()==((int)S.size())){
            ans.push_back(curr);
            return;
        }
        if(S[index]>='0' && S[index]<='9')
            ok(S, curr+S[index], index+1);
        else{
            ok(S,curr+(char)(toupper(S[index])),index+1);
            ok(S,curr+(char)(tolower(S[index])),index+1);
        }
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        int n=S.size();
        string curr="";
        ok(S,curr,0);
        return ans;
    }
};
