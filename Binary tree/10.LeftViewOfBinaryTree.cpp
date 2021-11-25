void Helper (Node *root,vector<int>&v,int max)
{
    if(!root) return;
     if(v[max]==0)
     v[max]=root->data; 
     Helper(root->left,v,max+1); 
     Helper(root->right,v,max+1); 
    
}
int Height(Node *r)
{
    if(!r) return 0;
    int x,y;
    x=Height(r->left);
    y=Height(r->right);
    return 1+max(x,y);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here 
   int x=Height(root);
   vector<int>v(x,0);  
   Helper(root,v,0);
   return v;
}