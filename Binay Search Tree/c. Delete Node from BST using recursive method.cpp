int Height(Node *root)
{
    if(!root) return 0;
    int x=Height(root->left);
    int y=Height(root->right);
    return 1+max(x,y);
}
Node *InPre(Node *root)
{  
    while(root->right)
    {
        root=root->right;
    }
    return root;
}
Node *InSucc(Node *root)
{ 
    while(root->left)
    {
        root=root->left;
    }
    return root;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int x) {
    if(!root) return root;
    Node *temp;
     if(x<root->data)
    root->left=deleteNode(root->left,x);
    else
    if(x>root->data)
    root->right=deleteNode(root->right,x);
    else 
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else
        if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        //if both childs exist then we can replace the root's data with inorder predecessor 
        // or inorder successor but we prefer to choose between them considering the height of 
        //left and right subtree. whose height is greater, we replace the root's data from the data
        // present in larger subtree.
        if(Height(root->left)>Height(root->right))
        {
            temp=InPre(root->left);
            root->data=temp->data;
            root->left=deleteNode(root->left,temp->data);
        }
        else
        {
            temp=InSucc(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }
}
