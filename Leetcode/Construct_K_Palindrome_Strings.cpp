class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>a(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        int even=0;
        int odd=0;
        for(int i=0;i<26;i++){
            if(a[i]%2!=0){
                odd++;
                even+=(a[i]-1)/2;
            }
            else{
                even+=(a[i]/2);
            }
        }
        if(k>n) return false;
        if(k<odd) return false;
        return true;
    }
};
