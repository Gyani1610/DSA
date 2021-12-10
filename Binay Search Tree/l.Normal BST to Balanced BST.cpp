void inorder(vector<Node*>&v,Node *root)
{
    if(!root) return;
    inorder(v,root->left);
    v.push_back(root);
    inorder(v,root->right);
}
Node * MakeBST(vector<Node*>&v,int s,int e)
{
    if(s>e) return NULL; 
    int mid=(e+s)/2; 
    Node *root=v[mid];
    root->left=MakeBST(v,s,mid-1);
    root->right=MakeBST(v,mid+1,e);
    return root;
}
Node* buildBalancedTree(Node* root)
{
    vector<Node*>v;
	inorder(v,root);
	return MakeBST(v,0,v.size()-1);
	
}
