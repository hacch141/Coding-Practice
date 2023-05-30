// Delete all occurrences of a given key in a doubly linked list

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* head = *head_ref;
        Node* newHead = NULL;
        while(head) {
            Node* prevNode = head->prev;
            Node* nextNode = head->next;
            Node* currNode = head; 
            if(head->data == x) {
                if(nextNode) {
                    nextNode->prev = prevNode;
                }
                if(prevNode) {
                    prevNode->next = nextNode;
                }
                delete(currNode);
            }
            else {
                if(!newHead) newHead = head;
            }
            head = nextNode;
        }
        *head_ref = newHead;
    }
};

// T : O(N)
// S : O(1)
