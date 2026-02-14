// Linked List that is Sorted Alternatingly

class Solution {
    public ListNode merge(ListNode head1, ListNode head2) {
        ListNode head = new ListNode(-1);
        ListNode dummy = head;
        while (head1 != null && head2 != null) {
            if (head1.val <= head2.val) {
                dummy.next = head1;
                head1 = head1.next;
            }
            else {
                dummy.next = head2;
                head2 = head2.next;
            }
            dummy = dummy.next;
        }

        if (head1 != null) dummy.next = head1;
        if (head2 != null) dummy.next = head2;

        return head.next;
    }

    public ListNode sortList(ListNode head) {

        if (head == null || head.next == null) return head;

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode l1 = sortList(prev.next);
        prev.next = null;
        ListNode l2 = sortList(head);

        return merge(l1, l2);
    }
}

// ================================================================

Node* reverse(Node* head) {
    if(!head || !head->next) return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* merge(Node* l1, Node* l2) {
    Node* temp = new Node(-1);
    Node* dummy = temp;
    while(l1 && l2) {
        if(l1->data < l2->data) {
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
        }
        else {
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }
    }
    if(l1) dummy->next = l1;
    if(l2) dummy->next = l2;
    return temp->next;
}

void sort(Node **head)
{
     // Code here
    Node* curr = *head;
    
    if(!curr->next) return;
    
    Node* asc = new Node(-1);
    Node* dummy1 = asc;
    Node* dsc = new Node(-1);
    Node* dummy2 = dsc;
    
    while(curr) {
        asc->next = curr;
        asc = asc->next;
        curr = curr->next;
        
        if(curr) {
            dsc->next = curr;
            dsc = dsc->next;
            curr = curr->next;
        }
    }
    asc->next = NULL;
    dsc->next = NULL;
    dummy1 = dummy1->next;
    dummy2 = dummy2->next;
    dummy2 = reverse(dummy2);
    
    *head = merge(dummy1,dummy2);
    return;
}

// T : O(N)
// S : O(1)
