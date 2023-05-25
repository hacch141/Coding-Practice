// Add two numbers represented by linked lists

class Solution
{
    public:
    
    struct Node* rev(struct Node* head) {
        if(!head || !head->next) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* l1 = rev(first);
        Node* l2 = rev(second);
        
        int carry = 0;
        Node* dummy = new Node(-1);
        Node* ans = dummy;
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            ans->next = new Node(sum%10);
            carry = sum/10;
            ans = ans->next;
        }
        return rev(dummy->next);
    }
};
// T : O(N + M)
// S : O( max(N,M) )
