class Solution {
public:
    int minCharacters(string a, string b) {
        int mini=1e5+5;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<26;i++){
            char x=(char)('a'+i);
            int total=0;
            for(int j=0;j<n;j++){
                if(a[j]!=x) total++;
            }
            for(int j=0;j<m;j++){
                if(b[j]!=x) total++;
            }
            mini=min(mini,total);
        }
        for(int i=1;i<26;i++){
            char x=(char)('a'+i);
            int total=0;
            // a is greater than b
            for(int j=0;j<n;j++){
                if(a[j]>=x) continue;
                else total++;
            }
            for(int j=0;j<m;j++){
                if(b[j]<x) continue;
                else total++;
            }
            mini=min(mini,total);
            total=0;
            // b is greater than a
            for(int j=0;j<m;j++){
                if(b[j]>=x) continue;
                else total++;
            }
            for(int j=0;j<n;j++){
                if(a[j]<x) continue;
                else total++;
            }
            mini=min(mini,total);
        }
        return mini;
    }
};
