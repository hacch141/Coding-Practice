// Intersection of Two Linked Lists

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        unordered_map<int,int> mp;
        Node* curr1 = head2;
        while(curr1 != NULL) {
            mp[curr1->data]++;
            curr1 = curr1->next;
        }

        Node* curr2 = new Node(0);
        Node* end = curr2;
        while(head1 != NULL) {
            if(mp[head1->data]>0) {
                end->next = new Node(head1->data);
                end = end->next;
            }
            head1 = head1->next;
        }
        return curr2->next;
    }
}

// T : O(N+M)
// S : O(N+M)
