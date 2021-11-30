void inorder(Node *root,vector<int>&v)
  {
      if(!root) return;
      inorder(root->left,v);
      v.push_back(root->data);
      inorder(root->right,v);
  }

//Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>v; 
	    for(int i=0;i<nums.size();i++)
	     v.push_back({nums[i],i});
	     sort(v.begin(),v.end());
	     int count=0;
	    for(int i=0;i<v.size();i++)
	    {
	        if(v[i].second==i)
	        continue;
	        else
	        {
	            count++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return count;
	}
    int SwapBinaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>v;
        inorder(root,v); 
       int swap= minSwaps(v);
        return swap;
    }