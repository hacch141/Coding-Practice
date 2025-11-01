// 3217. Delete Nodes From Linked List Present in Array

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> st = new HashSet<>();
        for (int i : nums) st.add(i);
        ListNode curr = new ListNode(-1, head);
        ListNode tmp = curr;
        while(curr != null && curr.next != null) {
            if (st.contains(curr.next.val)) curr.next = curr.next.next;
            else curr = curr.next;
        }
        return tmp.next;
    }
}
