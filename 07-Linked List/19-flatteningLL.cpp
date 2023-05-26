/*Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.*/

Node* merge(Node*a, Node*b){
    if(!a) return b;
    if(!b) return a;
    
    Node* ans = 0;
    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom, b);
    }
    else{
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}
    
Node *flatten(Node *root)
{
   if(!root) return 0;
   
   Node* mergedLL = merge(root, flatten(root->next));
   return mergedLL;
}