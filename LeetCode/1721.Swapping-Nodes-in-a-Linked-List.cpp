// 1721. Swapping Nodes in a Linked List

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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        int front, back;
        ListNode* temp = head;
        while(temp) {
            n++;
            if(n==k) front = temp->val;
            temp = temp->next;
        }
        
        temp = head;
        int cnt = n-k+1;
        for(int i=1; i<cnt; i++) {
            temp = temp->next;
        }
        back = temp->val;

        temp = head;
        for(int i=1; i<=max(cnt,k); i++) {
            if(i==k) temp->val = back;
            if(i==cnt) temp->val = front;
            temp = temp->next;
        }

        return head;
    }
};
