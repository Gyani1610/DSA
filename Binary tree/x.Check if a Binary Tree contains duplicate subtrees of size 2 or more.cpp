class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node *root,map<string,int>&m)
    {
        if(!root) return "$";
        string s="";
        if(!root->left&&!root->right) 
        {
            s=to_string(root->data);
            return s;
        }
        s=s+to_string(root->data);
        s=s+solve(root->left,m);
        s=s+solve(root->right,m);
        m[s]++;
        return s;
    }
     
    
    int dupSub(Node *root) { 
         map<string,int>m;  
         solve(root,m);
         for(auto x:m)
         if(x.second>=2) 
         return 1; 
         
         return 0;
    }
};