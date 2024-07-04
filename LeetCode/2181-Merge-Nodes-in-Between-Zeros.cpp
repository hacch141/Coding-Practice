// 2181. Merge Nodes in Between Zeros

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* dummy = newHead;
        head = head->next;
        int sum = 0;
        while(head) {
            if(head->val == 0) {
                newHead->next = new ListNode(sum);
                newHead = newHead->next;
                sum = 0;
            }
            else {
                sum += head->val;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
