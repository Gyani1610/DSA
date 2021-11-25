class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        int x,y;
        if(node==NULL)
        return 0;
        x=height(node->left);
        y=height(node->right);
        return x>y?x+1:y+1;
    }
};