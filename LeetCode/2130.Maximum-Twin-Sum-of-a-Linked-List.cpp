// 2130. Maximum Twin Sum of a Linked List

class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp && temp->next) {
            n += 2;
            temp = temp->next->next;
        }

        temp = head;
        stack<int> st;
        for(int i=0; i<n/2; i++) {
            st.push(temp->val);
            temp = temp->next;
        }

        int ans = INT_MIN;
        for(int i=0; i<n/2; i++) {
            ans = max(ans,st.top()+temp->val);
            temp = temp->next;
            st.pop();
        }
        return ans;
    }
};


// Without using stack
class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        if(!head || !head->next) return head;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverse(slow);

        int ans = 0;
        while(temp) {
            ans = max(ans,temp->val+head->val);
            temp = temp->next;
            head = head->next;
        }
        return ans;
    }
};
