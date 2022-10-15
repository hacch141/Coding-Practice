// 707. Design Linked List

class MyLinkedList {
public:
    struct Node{
        int val;
        Node *next,*prev;
        Node(int x){
            val=x,next=prev=NULL;
        }
    };
    Node *head;
    int size;
    
public:
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node* curr=head;
        
        for(int i=0;i<index;i++) 
            curr = curr->next;
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node *newNode=new Node(val);
        newNode->next=head;
        if(head) {
            head->prev=newNode;
        }
        head=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        
        if(index==0){
            addAtHead(val);
            return;
        }
        
        Node *newNode=new Node(val);
        Node *prev=head;
        
        for(int i=0;i<index-1;i++){
            prev=prev->next;
        }
        
        newNode->next=prev->next;
        prev->next=newNode;
        newNode->prev=prev;
        if(newNode->next) {
            newNode->next->prev=newNode;
        } 
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index<0) return;
        
        if(index==0){
            Node *temp=head;
            head=head->next;
            delete temp;
            size--;
            return;
        }
        
        Node *del=head;
        for(int i=0;i<index;i++){
            del=del->next;
        }
        
        if(del->prev) del->prev->next=del->next;
        if(del->next) del->next->prev=del->prev;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
