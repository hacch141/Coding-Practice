// 92. Reverse Linked List II

class Solution {
public:

    ListNode* rev(ListNode* head, ListNode* prev) {
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head->next || (left==right)) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* start = dummy;
        ListNode* end = dummy;

        for(int i=1; (i<left) && start; i++) {
            start = start->next;
        }

        for(int i=1; (i<=right) && end; i++) {
            end = end->next;
        }

        ListNode* next;
        next = end->next;
        end->next = NULL;

        ListNode* reverse = rev(start->next,next);
        start->next = reverse;
        
        return dummy->next;
    }
};

// T : O(N)
// S : O(1)
