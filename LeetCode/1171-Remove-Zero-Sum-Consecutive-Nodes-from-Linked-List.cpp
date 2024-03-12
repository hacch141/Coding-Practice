// 1171. Remove Zero Sum Consecutive Nodes from Linked List

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        map<int,ListNode*> mp;
        int pref = 0;
        mp[0] = dummy;
        while(head) {
            pref += head->val;
            if(mp.find(pref) != mp.end()) {
                ListNode* start = mp[pref];
                ListNode* temp = start->next;
                int sum = pref;
                while(temp != head) {
                    sum += temp->val;
                    mp.erase(sum);
                    temp = temp->next;
                }
                start->next = head->next;
            }
            else {
                mp[pref] = head;
            }
            head = head->next;
        }
        ListNode* newHead = dummy->next;
        delete(dummy);
        return newHead;
    }
};
