 void helper(Node *root,Node **prev,int *flag)
    {
        if(!root)
        return;
        helper(root->left,prev,flag); 
        if(*prev==NULL)
        *prev=root;
        else
        {
            if((*prev)->data>=root->data)
            {
                *flag=0;
                return;
            }
            *prev=root;
        } 
        helper(root->right,prev,flag);
        
    }
    bool isBST(Node* root) 
    {
        // Your code here
        int flag=1;
        Node *prev=NULL;
        helper(root,&prev,&flag);
        if(flag)
        return true;
        else
        return false;
    }
