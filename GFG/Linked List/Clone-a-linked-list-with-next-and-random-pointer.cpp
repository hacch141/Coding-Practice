class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        
        Node* itr = head;
        while(itr) {
            if(itr->arb) {
                itr->next->arb = itr->arb->next;
            }
            itr = itr->next->next;
        }
        
        Node* dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node* fast;
        while(itr) {
            fast = itr->next->next;
            temp->next = itr->next;
            temp = temp->next;
            itr->next = fast;
            itr = fast;
        }
        return dummy->next;
    }
};
