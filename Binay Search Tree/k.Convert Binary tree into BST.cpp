class Solution{
  public:
        int i=0; 
  void inorder(Node *root,vector<int>&v)
  {
      if(!root) return;
      inorder(root->left,v);
      v.push_back(root->data);
      inorder(root->right,v);
  } 
	
	void  CreateBST(Node *root,vector<int>&v)
	{
	    if(!root) return;
	    CreateBST(root->left,v);
	    root->data=v[i];
	    i++;
	    CreateBST(root->right,v);
	}
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        CreateBST(root,v);
        return root;
    }
};
