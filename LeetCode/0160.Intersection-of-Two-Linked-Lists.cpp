// 160. Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};

class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ll1Len = 0;
        int ll2Len = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while(curr1 != NULL) {
            ll1Len++;
            curr1 = curr1->next;
        }
        while(curr2 != NULL) {
            ll2Len++;
            curr2 = curr2->next;
        }
        
        int len = abs(ll1Len-ll2Len);
        if(ll1Len > ll2Len) {
            for(int i=0; i<len; i++) {
                headA = headA->next;
            }
        }
        else {
            for(int i=0; i<len; i++) {
                headB = headB->next;
            }
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {  // 2nd Method
//         unordered_map<ListNode*,int> mp;
//         while(headA != NULL) {
//             mp[headA]++;
//             headA = headA->next;
//         }
//         while(headB != NULL) {
//             if(mp[headB]>0) {
//                 return headB;
//             }
//             headB = headB->next;
//         }
//         return NULL;
    }
};
