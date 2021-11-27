// This function should return head to the DLL
class Solution
{
    public: 
    void helper(Node* root,Node **prev,Node **head)
    {
        if(!root) return;
        helper(root->left,prev,head);
        
       
        
        if(*head==NULL)//updating head node with the leftmost node of tree
        {
            *head=root;  
            //If root is leftmost node that time prev =null,hence we can't access its right node
            //and we just update the prev node for first time with root node;
             *prev=root; 
        }
        else
        {
             root->left=*prev;//putting the prev node to left(prev) pointer of current node.
             (*prev)->right=root;//just updating right(next) pointer of prev node with current node.
             *prev=root; 
        } 
        
        helper(root->right,prev,head); 
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    { 
        Node *prev=NULL,*head=NULL;
        helper(root,&prev,&head); 
        return head;
    }
};
