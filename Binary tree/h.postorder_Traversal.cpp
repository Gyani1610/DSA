//Function to return a list containing the postorder traversal of the tree.

         
    /******             BY Recursion             ******/

   void helper(Node *root,vector<int>&v)
    {
        if(!root) return;
        helper(root->left,v);
        helper(root->right,v);
        v.push_back(root->data);
    }

   vector<int> postOrder(Node* root) {
        // Your code here
        vector<int>v;
        helper(root,v);
        return v;
    } 
    
     
    /******             BY Iteration             ******/
vector <int> postOrder(Node* root)
{
  // Your code here
  stack<Node*>s;
  vector<int>v;
  Node *curr=root;
  while(!s.empty()||curr)
  {
      if(curr)
      {
          if(curr->right)
          s.push(curr->right);
          s.push(curr);
          curr=curr->left;
      }
      else
      {
          curr=s.top();
          s.pop();
          if(curr->right&&!s.empty()&&curr->right==s.top())
          {
              Node *temp=curr;
              curr=s.top();
              s.pop();
              s.push(temp); 
              
          }
          else
          {
              v.push_back(curr->data);
          curr=NULL;
          }
      }
  }
  return v;
}