int idx=0;
    TreeNode * helper(vector<int>&v,int strt,int end)
    {
        if(idx>=v.size()||v[idx]<strt||v[idx]>end)
            return NULL;
        int val=v[idx];
        idx++;
        TreeNode *t=new TreeNode(val);
        t->left=helper(v,strt,val);
        t->right=helper(v,val,end);
        return t;
    }
    TreeNode* bstFromPreorder(vector<int>& v) {
        
        return helper(v,INT_MIN,INT_MAX);
    }
