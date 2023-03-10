// 382. Linked List Random Node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int size = 0;
ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        temp = head;
    }
    
    int getRandom() {
        int n = rand()%size;
        ListNode* currptr = temp;
        while(n--) {
            if(currptr) currptr = currptr->next;
        }
        if(currptr) return currptr->val;
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
