class Solution{
  /****Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) **/
  
  
    public:
    int Dist_from_root_to_node(Node *root,int key,int dis)
    {
        if(!root) return 0;
        
        if(root->data==key)
        return dis;
        
        int x=Dist_from_root_to_node(root->left,key,dis+1);
        int y=Dist_from_root_to_node(root->right,key,dis+1);
        
        return max(x,y);
    }
    Node* find_lca(Node* root,int a,int b)
    {
        if(!root) return NULL;
        
        if(root->data==a||root->data==b)
        return root;
        
        Node *left=find_lca(root->left,a,b);
        Node *right=find_lca(root->right,a,b);
        
        if(left&&right) return root;
        
        if(left) return left;
        else return right;
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        int x=Dist_from_root_to_node(root,a,0);
        int y=Dist_from_root_to_node(root,b,0);
        Node *lca=find_lca(root,a,b);
        int z=Dist_from_root_to_node(root,lca->data,0); 
        return x+y-2*z;
    }
};
