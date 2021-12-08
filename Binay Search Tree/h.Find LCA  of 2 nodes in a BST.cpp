Node* LCA(Node *root, int n1, int n2)
{
   if(!root) return NULL;
   
   if(root->data==n1||root->data==n2)
   return root;
   
   Node* left_lca=LCA(root->left,n1,n2);
   Node* right_lca=LCA(root->right,n1,n2);
   
   if(right_lca&&left_lca)
   return root;
   
   if(right_lca) return right_lca;
   else return left_lca;
}
