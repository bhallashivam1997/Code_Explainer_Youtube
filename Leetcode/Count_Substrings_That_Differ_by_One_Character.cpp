class Solution {
public:
    
    int check(string ok, string t){
        // cout<<"in "<<ok<<"\n";
        int total=0;
        int n=ok.size();
        for(int i=0;i<(int)t.size()-(int)ok.size()+1;i++){
            int sum=0;
            for(int j=0;j<(int)ok.size();j++){
                if(ok[j]==t[i+j])
                    sum++;
            }
            if(n-sum==1)
                total++;
        }
        return total;
    }
    
    int countSubstrings(string s, string t) {
        int ans=0;
        int n=s.size();
        string ok="";
        for(int i=0;i<n;i++){
            ok="";
            for(int j=i;j<n;j++){
                ok=ok+(char)(s[j]);
                ans+=check(ok,t);
            }
        }
        return ans;
    }
};
