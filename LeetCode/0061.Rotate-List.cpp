// 61. Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp = head;
        int len = 1;
        while(temp->next) {
            temp = temp->next;
            len++;
        }
        k = len - k%len;
        temp->next = head;
        while(k--) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
