// 24. Swap Nodes in Pairs

// Recursion
class Solution {
public:

    ListNode* solve(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* prev = head->next;
        head->next = solve(head->next->next);
        prev->next = head;
        return prev;
    }

    ListNode* swapPairs(ListNode* head) {
        return solve(head);
    }
};


// Iterative
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* prev = temp;
        ListNode* curr = head;
        
        while(curr && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            curr = curr->next;
            prev = prev->next->next;
        }
        return temp->next;
    }
};
