// 23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;

        ListNode head = new ListNode();
        ListNode dummy = head;
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (int i = 0; i < n; i++) {
            if (lists[i] != null) pq.add(lists[i]);
        }

        while (!pq.isEmpty()) {
            ListNode curr = pq.poll();
            dummy.next = curr;
            dummy = dummy.next;
            if (curr.next != null) pq.add(curr.next);
        }

        return head.next;
    }
}
