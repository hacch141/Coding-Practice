// Doubly linked list Insertion at given position

void addNode(Node *head, int pos, int data)
{
   // Your code here
   for(int i=0; i<pos; i++) {
       head = head->next;
   }
   
   if(!head->next) {
       Node* newNode = new Node(data);
       head->next = newNode;
       head->next->prev = head;
   }
   
   else {
       Node* next = head->next;
       Node* newNode = new Node(data);
       head->next = newNode;
       head->next->prev = head;
       newNode->next = next;
       next->prev = newNode;
   }
}

// T : O(N)
// S : O(1)
