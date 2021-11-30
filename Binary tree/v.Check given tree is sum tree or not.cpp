
class Solution
{
    public:
    int helper(Node *root,int *flag)
    {
        if(!root) return 0;
        int x=helper(root->left,flag);
        int y=helper(root->right,flag); 
        if(x==0&&y==0)
        {
            *flag=1;
        }
        else
        if(x+y!=root->data)
        *flag=0; 
        return x+y+root->data;
    }
// Should return true if tree is Sum Tree, else false
    bool isSumTree(Node* root)
    {
         // Your code here
         int flag=0;
         int x=helper(root,&flag);
         if(flag)
         return true;
         else
         return false;
    }
};