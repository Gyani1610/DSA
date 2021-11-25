class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>v;
      if(node==NULL)
      return v;
      queue<Node*>q; 
      q.push(node);
      while(!q.empty())
      {
          v.push_back(q.front()->data);
          if(q.front()->left)
          q.push(q.front()->left);
          
          if(q.front()->right)
          q.push(q.front()->right); 
          
          q.pop();
          
      }
      return v;
      
    }
};