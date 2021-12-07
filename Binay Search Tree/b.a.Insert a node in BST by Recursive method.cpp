Node* insert(Node* root, int key)
{
    if(!root)
    {
        Node *n=new Node(key);
        root=n;
        return root;
    }
    if(key<root->data)
    {
        root->left=insert(root->left,key); 
    }
    else
    {
        if(key>root->data)
        root->right=insert(root->right,key);
        else
        return root;//if data is equal to any node;
    }
}
