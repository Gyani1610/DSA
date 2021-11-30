class Solution{
  public:
    /*You are required to complete this method*/
    int maxm=0,c=0;
    int checkHeight(Node *root,int *flag)
    {
        if(!root) return 0;
        c++;
        int x=checkHeight(root->left,flag);
        int y=checkHeight(root->right,flag);
        if(x==0&&y==0)
        {
            if(maxm==0)
            maxm=c; 
            else
            if(c!=maxm)
            *flag=0; 
        }
        c--; 
        
    }
    bool check(Node *root)
    {
        //Your code here
        int flag=1;
        int x=checkHeight(root,&flag);
        if(flag) return true;
        else return false;
    }
};