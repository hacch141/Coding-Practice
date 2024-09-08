// 725. Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* dummy = head;
        while(dummy) {
            len++;
            dummy = dummy->next;
        }

        vector<ListNode*> ans;
        int l = len / k, mod = len % k;
        while(head) {
            ans.push_back(head);
            for(int i = 0; i < l - 1 + (mod > 0); i++) {
                head = head->next;
            }
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
            mod--;
        }

        while(ans.size() < k) ans.push_back(nullptr);
        
        return ans;
    }
};
