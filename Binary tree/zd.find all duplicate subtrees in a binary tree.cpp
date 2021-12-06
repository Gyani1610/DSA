string solve(Node *root,unordered_map<string,int>&m,vector<Node *>&ans)
{
    if(!root) return "";
    
    string s="(";
    s+=solve(root->left,m,ans);
    s+=to_string(root->data);
    s+=solve(root->right,m,ans);
    s+=")";
    if(m[s]==1)
    ans.push_back(root);
    m[s]++;
     return s;
}
vector<Node*> printAllDups(Node* root)
{ 
    unordered_map<string,int>m;
    vector<Node *>ans; 
    solve(root,m,ans); 
    return ans;
}
