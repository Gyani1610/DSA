class Solution{
    public:
    Node* MakeTree(int in[],int instart,int inend,int pre[],int prestart,int preEnd,map<int,int>&m)
    {
        if(prestart>preEnd||instart>inend)//if there is no left and right subtree of root then return null;
        return NULL;
        
        Node *root=new Node(pre[prestart]);//creating new node
        
        int inRoot=m[pre[prestart]];//storing index of root node from inorder array
        int leftNums=inRoot-instart;//finding the number of all elements present left to inRoot
        
        root->left=MakeTree(in,instart,inRoot-1,pre,prestart+1,prestart+leftNums,m);//left subtree call
        root->right=MakeTree(in,inRoot+1,inend,pre,prestart+leftNums+1,preEnd,m);//right subtree call;
        return root; 
    }
    Node* buildTree(int in[],int pre[], int n)
    { 
        map<int,int>m;
        for(int i=0;i<n;i++)
        m[in[i]]=i;
        Node *root=MakeTree(in,0,n-1,pre,0,n-1,m);
        return root;
    }
};