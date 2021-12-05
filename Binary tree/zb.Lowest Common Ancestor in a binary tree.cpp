class Solution
{
    public: 
    //Function to return the lowest common ancestor in a Binary Tree.
     
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root) return NULL;
       
       // If either n1 or n2 matches with root's key, report
        // the presence by returning root (Note that if a key is
        // ancestor of other, then the ancestor key becomes LCA
       if(root->data==n1||root->data==n2)
       return root;
       
       // Look for keys in left and right subtrees
       Node* left_lca=lca(root->left,n1,n2);
       Node* right_lca=lca(root->right,n1,n2);
       
         // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
       if(left_lca&&right_lca)
       return root;
       
       // Otherwise check if left subtree or right subtree is LCA
       if(left_lca)
       return left_lca;
       else
       return right_lca;
        
    }
};
