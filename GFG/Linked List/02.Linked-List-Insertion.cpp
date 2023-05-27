// Linked List Insertion

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node* temp = new Node(x);
       if(!head) return temp;
       
       temp->next = head;
       return temp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       Node* temp = new Node(x);
       if(!head) return temp;
       
       Node* dummy = head;
       while(dummy->next) {
           dummy = dummy->next;
       }
       dummy->next = temp;
       
       return head;
    }
};

// T : O(1) for insertAtBeginning() and O(N) for insertAtEnd()
// S : O(1)
