class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<int,Node*>>q;
        vector<int>v;
        map<int,int>m;
        q.push({0,root});
        while(!q.empty())
        {
            Node *temp=q.front().second;
            int col=q.front().first;
            q.pop();
            m[col]=temp->data;
            if(temp->left)
            q.push({col-1,temp->left});
            if(temp->right)
            q.push({col+1,temp->right});
        }
        for(auto num :m)
        v.push_back(num.second);
        
        return v; 
    }
};