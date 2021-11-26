class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
   
         
    /******             BY Recursion             ******/
   
   void helper(Node *root,vector<int>&v)
    {
        if(!root) return;
        helper(root->left,v);
        v.push_back(root->data);
        helper(root->right,v);
    }

   vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>v;
        helper(root,v);
        return v;
    }
     
    /******             BY Iteration             ******/
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>v;
        stack<Node*>s; 
        Node *curr=root;
        while(!s.empty()||curr)
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=s.top();
                v.push_back(s.top()->data);
                s.pop();
                curr=curr->right;
            } 
        }
        return v;
    }
};