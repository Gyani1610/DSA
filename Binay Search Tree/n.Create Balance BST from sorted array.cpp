void MakeBST(vector<int>& v,vector<int>& ans,int l,int r)
    {
        if(l>r) return;
        int mid=(r-l)/2+l; 
        ans.push_back(v[mid]);
        MakeBST(v,ans,l,mid-1);
        MakeBST(v,ans,mid+1,r); 
    } 
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
         MakeBST(nums,ans,0,nums.size()-1); 
         return ans; 
        }
