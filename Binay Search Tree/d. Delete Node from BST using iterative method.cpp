Node *deleteNode(Node *root, int key) 
{
    Node* curr = root;
     Node* prev = NULL; 
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    if (curr == NULL) { 
        return root;
    }
  
    if (curr->left == NULL || curr->right == NULL) {
  
        Node* newCurr;
  
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
  
        if (prev == NULL)
            return newCurr;
  
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
  
        free(curr);
    }
  
    else {
        Node* p = NULL;
        Node* temp;
  
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
  
        if (p != NULL)
            p->left = temp->right; 
        else
            curr->right = temp->right;
 
        curr->data = temp->data;
        free(temp);
    }
    return root;
}
