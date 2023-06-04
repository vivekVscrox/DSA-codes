#include<iostream>
using namespace std;

class Node{
        public:
                int data;
                Node* next;
                //ctor
                Node(int data){
                        this->data = data;
                        this->next = NULL;
                }
                //dtor
                ~Node(){
                        int value = this->data;
                        if(next != NULL){
                                delete next;
                                next = NULL;
                        }
                        cout<<"Memory is free for node with data: "<<value<<endl;
                }
};

void print(Node* &head){
        if(head  == NULL){
                cout<<"List is empty!!"<<endl;
                return;
        }

        Node* temp = head;
        while(temp != NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
        }
        cout<<"x"<<endl;
}

int lenLL(Node* &head){
        int len = 0;
        Node* temp = head;
        while(temp!=NULL){
                len++;
                temp = temp->next;
        }
        return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);

        if(head == NULL){ //LL is empty
                head = newNode;
                tail = newNode;
                return;
        }
        //LL is non-empty
        newNode->next = head;
        head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){ //LL is empty
                head = newNode;
                tail = newNode;
                return;
        }
        //LL is non-empty
        tail->next = newNode;
        tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
        //if position given by user >= (lenLL + 2)
        if(position > lenLL(head)+1){
                cout<<"Invalid position!!"<<endl;
                return;
        }
        //insert at start
        if(position == 1){
                insertAtHead(head, tail, data);
                return;
        }

        Node* prevNode = head;
        int i=1;
        while(i < position-1){
                prevNode = prevNode->next;
                i++;
        }

        //inserting at last position
        if(prevNode->next == NULL){
                insertAtTail(head, tail, data);
                return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
}

void deletionFromPos(Node* &head, Node* &tail, int position){
        if(position > lenLL(head)){
                cout<<"Invalid position for deletion!!"<<endl;
                return;
        }

        if(head == NULL){
                cout<<"List is empty!!"<<endl;
                return;
        }
        if(position == 1){ //deleting start node
                Node* temp = head;
                head = head->next;
                //memory free
                temp->next = NULL;
                delete temp;
                return;
        }
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int i=1;
        while(i < position){
                prev = curr;
                curr = curr->next;
                i++;
        }

        prev->next = curr->next;
        if(curr->next == NULL){ //deleting last node
                tail = prev;
        }
        //memory free
        curr->next = NULL;
        delete curr;
}
/**********************************************************/
/* start your coding here...... */
//Approach1: counting method
void sortZeroOneTwo(Node* &head) {
        //step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }

        //step2: fill 0, 1 and 2s in the original ll
        temp = head;
                // fill zeroes
                while(zero--) {
                        temp -> data = 0;
                        temp = temp -> next;
                }

                //fill ones
                while(one--) {
                        temp -> data = 1;
                        temp = temp -> next;
                }

                //fill 2s
                while(two--) {
                        temp -> data = 2;
                        temp = temp -> next;
                }
}

//Approach2: Using dummy nodes
void insertAtTail2(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail2(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail2(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail2(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head, tail, 2, 1);
    insertAtPosition(head, tail, 0, 2);
    insertAtPosition(head, tail, 0, 3);
    insertAtPosition(head, tail, 1, 4);
    insertAtPosition(head, tail, 2, 5);
    insertAtPosition(head, tail, 0, 6);
    insertAtPosition(head, tail, 1, 7);
    insertAtPosition(head, tail, 2, 8);
    insertAtPosition(head, tail, 1, 9);

    print(head);

    Node* head1 = sortList(head);
    print(head1);
 
    return 0;
}