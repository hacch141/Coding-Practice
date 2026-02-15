// Merge k Sorted Lists

class Solution {

    public ListNode mergeKLists(ListNode[] lists) {

        // Min Heap based on node value
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.val, b.val));

        // Push head of each list
        for (ListNode node : lists) {
            if (node != null) {
                pq.offer(node);
            }
        }

        ListNode dummy = new ListNode(-1);
        ListNode current = dummy;

        while (!pq.isEmpty()) {

            ListNode node = pq.poll();
            current.next = node;
            current = current.next;

            if (node.next != null) {
                pq.offer(node.next);
            }
        }

        return dummy.next;
    }
}

// =========================================================================

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
