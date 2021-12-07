Node* insert(Node* root, int key) {
    Node *n;
    n=new Node(key);
    if(!root)//if BST is empty
    {
        root=n;
        return root;
    }
    Node *t=root;
    while(t)
    {
        if(t->data==key)//if key is eual to data it means key is already present, in this case, do nothing
        {
            free(n);
            return root;
        }
        else
        {
            if(t->data>key)     //if key is less than data
            {
                if(t->left==NULL)//if key is less than data and the curr node is the smallest node 
                {                //then add the new node with key value in left side
                    t->left=n;
                    return root;
                }
                else
                t=t->left;
            }
            else                //if key is greater than data
            {
                if(t->right==NULL)//if key is greater than data and curr node is the greatest node 
                {                  //then add the new node with key value in right side
                    t->right=n;
                    return root;
                }
                else    
                t=t->right;
            }
        } 
    }
}
