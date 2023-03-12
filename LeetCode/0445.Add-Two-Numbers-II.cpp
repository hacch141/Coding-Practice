// 445. Add Two Numbers II

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

    void rev(ListNode*& head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        rev(l1);
        rev(l2);
        int carry = 0;
        int sum = 0;
        ListNode* dummy = new ListNode(1);
        ListNode* curr = dummy;

        while(l1 || l2 || carry) {
            sum = 0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        rev(dummy->next);
        return dummy->next;
    }
};
