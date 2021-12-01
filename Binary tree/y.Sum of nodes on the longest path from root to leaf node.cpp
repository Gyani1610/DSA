class Solution
{
public: 
    vector<int> solve(Node *root)
    {
        if(!root) return {0,0}; 
        
        vector<int>x,y;
        
        x=solve(root->left);
        y=solve(root->right);  
        
        if(x[0]>y[0]) return {x[0]+1,x[1]+root->data};
        else
        if(y[0]>x[0]) return {y[0]+1,y[1]+root->data};
        else
        return {x[0]+1,max(x[1],y[1])+root->data};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        vector<int>v;
        v=solve(root);
        return v[1];
    }
};