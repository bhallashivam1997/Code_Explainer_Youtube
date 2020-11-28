class Solution {
public:
    
    bool ok(string seq, string w){
        for(int i=0;i<(int)seq.size();i++){
            bool flag=true;
            for(int j=0;j<(int)w.size();j++){
                if((j+i)<(int)seq.size() && seq[i+j]!=w[j]){
                    flag=false;
                }
                else if(i+j>=(int)seq.size())
                    return false;
            }
            if(flag)
                return true;
        }
        return false;
    }
    
    int maxRepeating(string seq, string word) {
        int maxi=0;
        int n=seq.size();
        int m=word.size();
        string new_word="";
        for(int i=0;i<n;i++){
            new_word+=(string)word;
            // cout<<"in "<<seq<<" "<<new_word<<"\n";
            if(new_word.size()<=seq.size() && ok(seq,new_word)){
                maxi=max(maxi,i+1);
            }
            else
                break;
        }
        return maxi;
    }
};
