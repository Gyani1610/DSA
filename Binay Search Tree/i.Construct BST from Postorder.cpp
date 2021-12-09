Node *constructTree (int post[], int size)
{
     stack<Node*> s;
     int i=size-1; 
     Node *root=new Node(post[i]); 
     s.push(root);
     i--;
     Node *temp,*t=root;
     while(i>=0)
     {
         if(post[i]>t->data)
         { 
             temp=new Node(post[i]);
             t->right=temp;
             s.push(t);
             i--;
             t=t->right;
         }
         else
         {
             if(s.empty())
             {
                 t->left=new Node(post[i]);
                 i--;
                 s.push(t->left);
                 t=t->left;
             }
             else
             {
                 if(post[i]<s.top()->data)
                 {
                     t=s.top();
                     s.pop();
                 }
                 else
                 {
                     t->left=new Node(post[i]);
                     i--;
                     s.push(t->left);
                     t=t->left;
                 }
             } 
         }
     }
     return root;
}
