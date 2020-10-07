class Solution {
public:
    
    int ok(vector<int>& A , int K){
        if(K==0)
            return 0;
        int n=A.size();
        int total=0;
        int diff=0;
        int j=0;
        vector<int>cnt(20002);
        for(int i=0;i<n;i++){
            if(cnt[A[i]]==0){
                diff++;
                cnt[A[i]]++;
            }
            else{
                cnt[A[i]]++;
            }
            if(diff<=K){
                total+=(i-j+1);
            }
            else{ 
                while(j<n && j<=i && diff>K){
                    cnt[A[j]]--;
                    if(cnt[A[j]]==0)
                        diff--;
                    j++;
                }
                total+=(i-j+1);
            }
        }
        return total;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return ok(A,K)-ok(A,K-1);
    }
};
