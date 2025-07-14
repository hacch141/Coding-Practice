// 1290. Convert Binary Number in a Linked List to Integer

class Solution {
public:
    ListNode* get_reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        ListNode* rev = get_reverse(head);
        int num = 0, bit = 0;
        while(rev) {
            if(rev->val) num |= (1 << bit);
            rev = rev->next;
            bit++;
        }
        return num;
    }
};
