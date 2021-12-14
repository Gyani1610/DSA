void inorder(Node *root,map<int,int>&m)
{
    if(!root) return;
    inorder(root->left,m);
    m[root->data]=1;
    inorder(root->right,m);
} 
bool check(Node *root,map<int,int>&m)
{ 
    if(!root) return false;
    bool l=check(root->left,m); 
    
    if(root->left==NULL&&root->right==NULL)
    {
        if((m[root->data-1]==1||root->data==1)&&m[root->data+1]==1) return true;
    } 
    bool r=check(root->right,m); 
    return l||r;
}
/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    map<int,int>m;
    inorder(root,m); 
    return check(root,m);
}
