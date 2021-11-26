//Function to return a list containing the preorder traversal of the tree.

         
    /******             BY Recursion             ******/

   void helper(Node *root,vector<int>&v)
    {
        if(!root) return;
        v.push_back(root->data);
        helper(root->left,v);
        helper(root->right,v);
    }

   vector<int> preorder(Node* root) {
        // Your code here
        vector<int>v;
        helper(root,v);
        return v;
    } 
    
     
    /******             BY Iteration             ******/

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>v;
  stack<Node*>s;
  Node *curr=root;
  while(!s.empty()||curr)
  {
      if(curr)
      {
          v.push_back(curr->data);
          s.push(curr);
          curr=curr->left;
      }
      else
      {
          curr=s.top();
          s.pop();
          curr=curr->right;
      }
  }
  return v;
}