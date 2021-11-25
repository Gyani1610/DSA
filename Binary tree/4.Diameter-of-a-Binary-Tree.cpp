int Helper(Node *root,int *ans)
{
    if(!root) return 0;
    int x,y;
    x=Helper(root->left,ans);
    y=Helper(root->right,ans);
    *ans=max(*ans,x+y+1);
    return x>y?x+1:y+1;
}
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here   
        int ans=0;
        int x=Helper(root,&ans);
        return ans;
    }
};
