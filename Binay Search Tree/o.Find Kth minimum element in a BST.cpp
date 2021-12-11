class Solution {
  public:
   int ans=0,i=0,flag=0;
    void inorder(Node *root,int k)
    {
        if(!root) return;
        inorder(root->left,k);
        i++;
        if(i==k)
        {
            flag=1;
            ans=root->data;
            return;
        } 
        inorder(root->right,k);
    } 
// Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        inorder(root,k);
        if(flag==0)
        return -1;
        else
        return ans;
    }
};
