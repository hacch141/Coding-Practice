// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* first = head;
        for(int i=0; i<=n; i++) {
            if(first == NULL) {
                if(i == n) {
                return head->next;   
            }
                return NULL;
            }
            first = first->next;
        }
        ListNode* second = head;
        while(first != NULL) {
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return head;
    }
};
