void printSum(Node *root,vector<int>&path,int k)
{
    if(!root) return;
    path.push_back(root->data);
    printSum(root->left,path,k);
    printSum(root->right,path,k);
    int f=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        f+=path[i];
        if(f==k)
        {
            for(int m=i;m<v.size()-1;m++)
            cout<<path[m]<<" ";
            cout<<endl;
        }
    }
        path.pop_back();
}
void PrintKsumPath(Node *root,int k)
{
    vector<int>path;
    printSum(root,path,k);
    return;
}
