class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        if(n1!=n2) return false;
        vector<int>a(26);
        vector<int>b(26);
        for(int i=0;i<n1;i++){
            a[w1[i]-'a']++;
        }
        for(int i=0;i<n2;i++){
            b[w2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]==0 && b[i]>0)
                return false;
            if(a[i]>0 && b[i]==0)
                return false;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
};
