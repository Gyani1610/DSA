class Solution
{
public:
    Node *prev=NULL;
    void populateNext(Node *root)
    {
        if(!root) return;
        
        populateNext(root->left);
        if(prev==NULL)
        prev=root;
        else
        {
            prev->next=root;
            prev=root;
        }
        populateNext(root->right);
    }
};
