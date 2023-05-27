// Delete node in Doubly Linked List

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
      Node* head = head_ref;
      if(x == 1) {
          head = head->next;
          head->prev = NULL;
          return head;
      }
      
      for(int i=1; i<x-1; i++) {
          head = head->next;
      }
      
      Node* temp = head->next;
      head->next = head->next->next;
      temp->next = NULL;
      temp->prev = NULL;
      if(head->next) head->next->prev = head;
      
      return head_ref;
    }
};

// T : O(N)
// S : O(1)
