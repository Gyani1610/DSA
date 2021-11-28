class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
     int helper(Node *root)
     {
         if(!root) return 0;
        int x=helper(root->left);
        int y=helper(root->right);
        int temp=root->data;
        root->data=x+y;
        return x+y+temp;
     }
    void toSumTree(Node *root)
    {
        helper(root); 
    }
};