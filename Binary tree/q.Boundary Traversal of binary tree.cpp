class Solution {
public:
    void leftNode(Node *root,vector<int>&v)
    { 
        if(!root) return;
        
        if(root->left)
        {
            v.push_back(root->data);
            leftNode(root->left,v);
        }
        else
        if(root->right)
        {
            v.push_back(root->data);
            leftNode(root->right,v);
        } 
    }
    void leafNode(Node *root,vector<int>&v)
    {
        if(!root) return;
        leafNode(root->left,v);
        if(root->right==NULL&&root->left==NULL)
        v.push_back(root->data);
        leafNode(root->right,v);
    } 
    void rightNode(Node *root,vector<int>&v) 
    { 
        if(!root) return;
        
        if(root->right)
        {
            rightNode(root->right,v);
            v.push_back(root->data);
        } 
        else
        if(root->left)
        {
            rightNode(root->left,v);
            v.push_back(root->data);
        } 
    }
    //Boundry traversal
    vector <int> boundary(Node *root)
    {
        vector<int>v;
        v.push_back(root->data);
        if(root->left)
        leftNode(root->left,v); 
        leafNode(root,v);
        if(root->right)
        rightNode(root->right,v);
        return v;
    }
};
