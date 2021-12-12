class Solution
{
public:
    void inorder(Node *root,vector<int>&v)
    {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        int i=0,j=v2.size()-1,c=0,sum; 
        while(i<v1.size()&&j>=0)
        {
            sum=v2[j]+v1[i]; 
            if(sum<x)
            i++;
            else
            {
                if(sum>x)
                j--;
                else
                {
                    i++;j--;
                    c++;
                }
            }
        } 
        return c;
    }
};
