// 2487. Remove Nodes From Linked List

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
        if(!head || !head->next) return head;
        ListNode *curr = head, *next = NULL, *prev = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = rev(head);
        ListNode* dummy = head;
        while(dummy && dummy->next) {
            if(dummy->next->val >= dummy->val) {
                dummy = dummy->next;
            }
            else {
                dummy->next = dummy->next->next;
            }
        }
        head = rev(head);
        return head;
    }
};
