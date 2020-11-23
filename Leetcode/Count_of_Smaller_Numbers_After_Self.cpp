class Solution {
public:
    struct Node{
        int val;
        int count;
        Node* left;
        Node* right;
        Node(int val, int count){
            this->val = val;
            this->count = count;
            this->left=NULL;
            this->right=NULL;
        }
    };
    
    int add(Node*& root , int val,int total){
        if(root==NULL){
            root=new Node(val,0);
            return total;
        }
        if(root->val < val){
            return root->count+(add(root->right,val,total+1));
        }
        else{
            root->count++;
            return add(root->left,val,total);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        Node* root = NULL;
        for(int i=n-1;i>=0;i--){
            ans[i]=add(root,nums[i],0);
        }
        return ans;
    }
};
