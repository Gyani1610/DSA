class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(!r1&&!r2) return true;
        if(r2==NULL||r1==NULL)
        return false;
        
        if(r1->data!=r2->data)
            return false; 
         bool x=isIdentical(r1->left,r2->left);
         bool y=isIdentical(r1->right,r2->right);
         return x&y;
    }
};