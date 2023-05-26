
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {   
        if(!head) return;
        Node* it = head;
        for(int i=0; i<M-1; i++){
            //if M nodes are not available
            if(!it) return;
            it = it->next;
        }  
        
        //it -> would be at Mth node
        if(!it) return;
        
        Node* MthNode = it;
        it = MthNode->next;
        for(int i=0; i<N; i++){
            if(!it) break;
            
            Node* temp = it->next;
            delete it;
            it = temp;
        }
        MthNode->next = it;
        //recursion aage ka solve krdega
        linkdelete(it, M, N);
    }
};

