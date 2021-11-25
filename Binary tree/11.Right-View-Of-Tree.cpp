class Solution
{
    public:
    void helper(Node *root,vector<int>&v,int max)
    {
        if(!root) return;
        if(v[max]==-1) v[max]=root->data;
        helper(root->right,v,max+1);
        helper(root->left,v,max+1);
    }
    int Height(Node *root)
    {
        if(!root) return 0;
        return 1+max(Height(root->left),Height(root->right));
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       int x=Height(root);
       vector<int>v(x,-1);
       helper(root,v,0);
       return v;
    }
};