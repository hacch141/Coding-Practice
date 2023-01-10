// 138. Copy List with Random Pointer

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
        // step 1 add new nodes 
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        // step 2 add random to the new nodes
        Node* itr = head;
        while(itr) {
            if(itr->random) {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        // step 3
        Node* dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node* fast;
        while(itr) {
            // fast points to next main node
            fast = itr->next->next;
            // add copy node to temp 
            temp->next = itr->next;
            // and move ahead
            temp = temp->next;
            // point to next main node
            itr->next = fast;
            // go to next main node
            itr = fast;
        }
        return dummy->next;
    }
};
