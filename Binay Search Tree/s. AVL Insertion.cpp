
class Solution{
  public:
    /*You are required to complete this method */
    
    int height(Node *n)
    {
        if(!n) return 0;
        return n->height;
    }
    
    int getBalFac(Node *n)
    {
        if(!n) return 0;
        return height(n->left)-height(n->right);
    }
    
    Node *leftRot(Node *n)
    {
        Node *nr=n->right;
        Node *nrl=nr->left;
        //rotation
        nr->left=n;
        n->right=nrl;
        //updating height 
        n->height=1+max(height(n->left),height(n->right));
        nr->height=1+max(height(nr->left),height(nr->right));
        // return the root node among three nodes on which rotation performed;
        return nr;
    }
    
    Node *rightRot(Node *n)
    {
        Node *nl=n->left;
        Node *nlr=nl->right;
        
        nl->right=n;
        n->left=nlr;
         
        //updating height 
        
        n->height=1+max(height(n->left),height(n->right));
        nl->height=1+max(height(nl->left),height(nl->right));
        
        return nl;
    }
    
    Node* insertToAVL(Node* node, int data)
    {
        if(!node) 
        return new Node(data);
        
        if(data<node->data)
        node->left=insertToAVL(node->left,data);
        else
        if(data>node->data)
        node->right=insertToAVL(node->right,data);
        else
        return node;
        
        node->height=1+max(height(node->left),height(node->right));
        
        int bf=getBalFac(node);
        
        //LL imbalance Condition
        if(bf>1&&data<node->left->data)
        return rightRot(node);
        
        //RR imbalance Condition
        if(bf<-1&&data>node->right->data)
        return leftRot(node);
        
        //LR imbalance Condition
        if(bf>1&&data>node->left->data)
        {
            node->left=leftRot(node->left);
            return rightRot(node);
        }
        
        //RL imbalance Condition
        if(bf<-1&&data<node->right->data)
        {
            node->right=rightRot(node->right);
            return leftRot(node);
        }
        
        return node;
    }
};
