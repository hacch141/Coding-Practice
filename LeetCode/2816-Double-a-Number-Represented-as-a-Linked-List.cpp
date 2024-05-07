// 2816. Double a Number Represented as a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* rev(ListNode* head) {
        ListNode *curr = head, *next = NULL, *prev = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        ListNode* dummy = head, *prev;
        int carry = 0;
        while(dummy) {
            int val = dummy->val;
            dummy->val = (2 * val + carry) % 10;
            carry = (2 * val + carry) / 10;
            prev = dummy;
            dummy = dummy->next;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        head = rev(head);
        return head;
    }
};
