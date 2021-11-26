vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>v;
    if(root==NULL)
    return v;
    queue<Node*>q;
    vector<int>temp;
    q.push(root); 
    while(!q.empty())
    {
        temp.push_back(q.front()->data);
        if(q.front()->right)
        q.push(q.front()->right);
        
        if(q.front()->left)
        q.push(q.front()->left);
        
        q.pop();
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        v.push_back(temp[i]); 
    }
    return v;
}
