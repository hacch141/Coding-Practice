// Segregate even and odd nodes in a Link List

class Solution {

    public Node divide(int N, Node head) {

        Node even = new Node(-1);
        Node dummy1 = even;

        Node odd = new Node(-1);
        Node dummy2 = odd;

        Node curr = head;

        while (curr != null) {

            if (curr.data % 2 == 1) {
                odd.next = curr;
                odd = odd.next;
            } else {
                even.next = curr;
                even = even.next;
            }

            curr = curr.next;
        }

        if (dummy2.next == null || dummy1.next == null) return head;

        even.next = dummy2.next;
        odd.next = null;

        return dummy1.next;
    }
}

// ========================================================================

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even = new Node(-1);
        Node* dummy1 = even;
        Node* odd = new Node(-1);
        Node* dummy2 = odd;
        Node* curr = head;
        
        while(curr) {
            if(curr->data%2==1) {
                odd->next = curr;
                odd = odd->next;
            }
            else {
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
        }
        
        if(odd->data==-1 || even->data==-1) return head;
        
        even->next = dummy2->next;
        odd->next = NULL;
        
        return dummy1->next;
    }
};

// T : O(N)
// S : O(1)
