// Delete all occurrences of a given key in a doubly linked list

class Solution {

    Node deleteAllOccurOfX(Node head, int x) {

        Node curr = head;

        while (curr != null) {

            if (curr.data == x) {

                // If node to be deleted is head
                if (curr == head) {
                    head = curr.next;
                }

                // Adjust previous pointer
                if (curr.prev != null) {
                    curr.prev.next = curr.next;
                }

                // Adjust next pointer
                if (curr.next != null) {
                    curr.next.prev = curr.prev;
                }
            }

            curr = curr.next;
        }

        return head;
    }
}


// T : O(N)
// S : O(1)
