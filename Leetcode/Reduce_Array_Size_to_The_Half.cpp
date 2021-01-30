class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        vector<int>a(100005);
        for(int i=0;i<n;i++){
            a[arr[i]]++;
        }
        sort(a.rbegin(),a.rend());
        int total=0;
        for(int i=0;i<n;i++){
            total+=a[i];
            if(total>=(n/2))
                return (i+1);
        }
        return n;
    }
};
