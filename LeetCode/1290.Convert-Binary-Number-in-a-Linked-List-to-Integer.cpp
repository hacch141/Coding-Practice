// 1290. Convert Binary Number in a Linked List to Integer

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

    void reverse(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getDecimalValue(ListNode* head) {
        reverse(head);
        int bit = 1;
        int num = 0;
        while(head) {
            if(head->val) num += bit;
            bit = bit << 1;
            head = head->next;
        }
        return num;
    }
};
