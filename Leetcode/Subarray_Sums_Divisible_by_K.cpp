class Solution {
public:
    int mod(int n , int M){
        return (n%M+M)%M;
    }
    int add(int a , int b, int M){
        return mod(mod(a,M)+mod(b,M) , M);
    }
    
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int>a;
        int n=A.size();
        int total_sum=0;
        a[0]=1;
        int total_subarray=0;
        for(int i=0;i<n;i++){
            total_sum=add(A[i],total_sum,K);
            total_subarray+=a[total_sum];
            a[total_sum]++;
        }
        return total_subarray;
    }
};
