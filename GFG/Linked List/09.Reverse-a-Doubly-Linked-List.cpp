// Reverse a Doubly Linked List
class Solution {

    Node reverseDLL(Node head) {

        Node prev = null;
        Node curr = head;

        while (curr != null) {
            Node next = curr.next;

            // Swap next and prev pointers
            curr.next = prev;
            curr.prev = next;

            prev = curr;
            curr = next;
        }

        return prev; // New head
    }
}

// =======================================================

Node* reverseDLL(Node * head)
{
    //Your code here
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

// T : O(N)
// S : O(1)
