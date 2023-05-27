// Rotate a Linked List

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* dummy = head;
        while(dummy->next) {
            dummy = dummy->next;
        }
        dummy->next = head;
        
        for(int i=0; i<k-1; i++) {
            head = head->next;
        }
        
        Node* newHead = head->next;
        head->next = NULL;
        
        return newHead;
    }
};
