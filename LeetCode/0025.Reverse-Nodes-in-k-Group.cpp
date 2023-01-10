// 25. Reverse Nodes in k-Group

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }

        ListNode* temp = head;
        int cnt = k;
        // check there exist group of k nodes or not
        // if not then return the head directly without any changes
        while(cnt--) {
            if(!temp) return head;
            temp = temp->next;
        }

        // reverse group of k nodes
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        while(curr!=NULL && count<k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // do recursive call for next nodes
        if(next != NULL) {
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
