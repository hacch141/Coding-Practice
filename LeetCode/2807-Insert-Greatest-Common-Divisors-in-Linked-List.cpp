// 2807. Insert Greatest Common Divisors in Linked List

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = new ListNode(head->val);
        ListNode* dummy = ans;
        head = head->next;
        while(head) {
            dummy->next = new ListNode(__gcd(dummy->val, head->val));
            dummy = dummy->next;
            dummy->next = head;
            dummy = dummy->next;
            head = head->next;
        }
        return ans;
    }
};
