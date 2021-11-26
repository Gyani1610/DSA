
class Solution{
    public:
    int helper(Node *root,int *ans)
    {
        if(!root) return 0;
        int lh=helper(root->left,ans);
        int rh=helper(root->right,ans);
        if(abs(lh-rh)>=2) *ans=0;
        return 1+max(lh,rh);
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int ans=1;
        helper(root,&ans);
        if(ans)
        return true;
        else return false;
    }
};