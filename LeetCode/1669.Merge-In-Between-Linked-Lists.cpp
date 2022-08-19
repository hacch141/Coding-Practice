// 1669. Merge In Between Linked Lists

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* slist2 = list2;
        ListNode* elist2 = list2;
        
        while(elist2->next != NULL) {
            elist2 = elist2->next;
        }
        
        ListNode* med1list1 = list1;
        
        for(int i=0; i<a-1; i++) {
            med1list1 = med1list1->next;
        }
        
        ListNode* med2list1 = list1;
        for(int i=0; i<=b; i++) {
            med2list1 = med2list1->next;
        }
        
        med1list1->next = slist2;
        elist2->next = med2list1;
        
        return list1;
    }
};
