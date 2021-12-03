
class Solution{
  public:
  map<Node*,int>dp;
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        if(!root) return 0; 
        
        //if that root is already visited then no need to visit further
        //just return the result of that node. 
        if(dp[root]) return dp[root];
        
        int include=root->data;
        if(root->left)
        include+=getMaxSum(root->left->left)+getMaxSum(root->left->right);
        if(root->right)
        include+=getMaxSum(root->right->left)+getMaxSum(root->right->right); 
        
        int exclude=getMaxSum(root->left)+getMaxSum(root->right);
        dp[root]=max(include,exclude);
        return dp[root];
    }
};