// Given a linked list of 0s, 1s and 2s, sort it.

class Solution
{
    public:
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        Node* zeros = new Node(-1);
        Node* ones = new Node(-1);
        Node* twos = new Node(-1);
        Node* dummy0 = zeros;
        Node* dummy1 = ones;
        Node* dummy2 = twos;
        
        while(head) {
            if(head->data == 0) {
                zeros->next = head;
                zeros = zeros->next;
            }
            else if(head->data == 1) {
                ones->next = head;
                ones = ones->next;
            }
            else {
                twos->next = head;
                twos = twos->next;
            }
            head = head->next;
        }
        
        ones->next = dummy2->next;
        zeros->next = dummy1->next;
        twos->next = NULL;
        return dummy0->next;
    }
};

// T : O(N)
// S : O(1)
