// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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

    bool isCritical(ListNode* head, int& prev) {
        if(prev == -1 || !head->next) return false;
        return (head->val > prev && head->val > head->next->val) || (head->val < prev && head->val < head->next->val);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mx = INT_MIN, mn = INT_MAX, cntNodes = 0, prevVal = -1, prevCritical = -1, firstCritical = -1;
        while(head) {
            cntNodes++;
            if(isCritical(head, prevVal)) {
                if(prevCritical != -1) {
                    mn = min(mn, cntNodes - prevCritical);
                    mx = max(mx, cntNodes - firstCritical);
                } else {
                    firstCritical = cntNodes;
                }
                prevCritical = cntNodes;
            }
            prevVal = head->val;
            head = head->next;
        }

        vector<int> ans;
        if(mx != INT_MIN) ans = {mn, mx};
        else ans = {-1, -1};

        return ans;
    }
};
