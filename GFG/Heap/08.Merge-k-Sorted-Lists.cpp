// Merge k Sorted Lists

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val >= b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto i : lists) {
            if(i) pq.push(i);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        while(!pq.empty()) {
            ListNode* a = pq.top();
            pq.pop();
            ans->next = a;
            ans = ans->next;
            a = a->next;
            if(a) pq.push(a);            
        }
        return dummy->next;
    }
};

// T : O(N * LogK)
// S : O(K)
