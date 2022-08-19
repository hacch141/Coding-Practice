// 234. Palindrome Linked List

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
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* curr1 = head;
        ListNode* curr2 = prev;
        
        while(curr2 != NULL) {
            if(curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    
//     bool isPalindrome(ListNode* head) {  //  2nd Method
//         stack<int> st;
//         ListNode* curr = head;
//         while(curr != NULL) {
//             st.push(curr->val);
//             curr = curr->next;
//         }
        
//         curr = head;
//         while(curr != NULL) {
//             if(st.top() != curr->val) {
//                 return false;
//             }
//             st.pop();
//             curr = curr->next;
//         }
//         return true;
//     }
};
