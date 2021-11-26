class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
     
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
        queue<pair<int,Node*>>q;
        map<int,int>m;
        q.push({0,root});
        while(!q.empty())
        {
            Node *temp=q.front().second;
            int col=q.front().first;
            q.pop();
            if(m[col]==0)
            {
                m[col]=temp->data;
            }
            if(temp->left)
            {
                q.push({col-1,temp->left});
            }
            if(temp->right)
            {
                q.push({col+1,temp->right});
            }
        } 
      map<int,int>::iterator it;
      for(it=m.begin();it!=m.end();it++)
      {
          v.push_back(it->second); 
      }
        return v;
    }

};