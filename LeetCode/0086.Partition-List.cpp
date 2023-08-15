// 86. Partition List

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ss = new ListNode(-1);
        ListNode* ls = new ListNode(-1);
        ListNode* se = ss;
        ListNode* le = ls;

        while(head) {
            if(head->val < x) {
                se->next = head;
                se = se->next;
            }
            else {
                le->next = head;
                le = le->next;
            }
            head = head->next;
        }

        se->next = ls->next;
        le->next = NULL;
        return ss->next;
    }
};
