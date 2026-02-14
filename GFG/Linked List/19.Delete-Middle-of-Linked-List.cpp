/// Delete Middle of Linked List

class Solution {
    public ListNode deleteMiddle(ListNode head) {
        
        // Edge case: single node
        if (head == null || head.next == null) {
            return null;
        }

        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;

        // Find middle node
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Delete middle node
        prev.next = slow.next;

        return head;
    }
}

// ========================================================

class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head.next == null) return null;

        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = prev.next.next;

        return head;
    }
}

// T : O(N)
// S : O(1)
