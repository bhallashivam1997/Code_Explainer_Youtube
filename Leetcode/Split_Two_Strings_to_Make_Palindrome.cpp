class Solution {
public:
    
    bool ok(string a, string b){
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[n-i-1]) break;
            cnt++;
        }
        if(2*cnt>=n) return true;
        int l=cnt;
        int r=n-cnt-1;
        for(int i=l;i<=r;i++){
            if(b[i]!=b[r-i+l]) return false;
        }
        return true;
    }
    
    
    bool checkPalindromeFormation(string a, string b) {
        bool ans=ok(a,b)|ok(b,a);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        ans|=ok(a,b);
        ans|=ok(b,a);
        return ans;
    }
};
