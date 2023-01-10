class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL || head->next==NULL || k==0) return head;
        int len = 1;
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
            len++;
        }
        k = k%len;
        temp->next = head;
        while(k--) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
