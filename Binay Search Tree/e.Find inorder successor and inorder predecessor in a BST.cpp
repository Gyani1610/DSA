Node *InPre(Node* root)
{
    while(root->right)
    root=root->right;
    return root;
}
Node *InSuc(Node* root)
{
    while(root->left)
    root=root->left;
    return root;
}
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return;
    if(key<root->key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        if(key>root->key)
        {
            pre=root; 
            findPreSuc(root->right,pre,suc,key);
        }
        else
        {
            if(root->left) pre=InPre(root->left);
            if(root->right) suc=InSuc(root->right);
            return;
        }
    }
}
