class Solution
{
    public:
    int ans=0,i=0;
    void inorder(Node *root,int k)
    {
        if(!root) return;
        inorder(root->right,k);
        i++; 
        if(i==k)
        {
          ans=root->data; 
          return;
        } 
        inorder(root->left,k);
    } 
    int kthLargest(Node *root, int k)
    {  
        inorder(root,k);   
        return ans; 
    }
};
