class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char>mp;
        set<char>x;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])==0 && x.count(t[i])==0){
                mp[s[i]]=t[i];
                x.insert(t[i]);
            }
            else if(mp.count(s[i])==0 && x.count(t[i]))
                return false;
            else if(mp[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};
