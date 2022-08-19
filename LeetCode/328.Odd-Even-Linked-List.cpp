// 328. Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* es = NULL;
        ListNode* ee = NULL;
        ListNode* os = NULL;
        ListNode* oe = NULL;
        bool flag = 0;
        
        for(ListNode* curr = head; curr != NULL ; curr = curr->next) {
            if(flag == 0) {
                if(es == NULL) {
                    es = curr;
                    ee = es;
                }
                else {
                    ee->next = curr;
                    ee = ee->next;
                }
                flag = 1;
            }
            else {
                if(os == NULL) {
                    os = curr;
                    oe = os;
                }
                else {
                    oe->next = curr;
                    oe = oe->next;
                }
                flag = 0;
            }
        }
        ee->next = os;
        oe->next = NULL;
        return es;
    }
};
