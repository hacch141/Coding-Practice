// Reverse a Linked List in groups of given size

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head) return NULL;
        
        node* prev = NULL;
        node* curr = head;
        node* next;
        int cnt = 0;
        while(curr && cnt<k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        head->next = reverse(next,k);
        
        return prev;
    }
};

// T : O(N)
// S : O(1)


// Leetcode
// Rec
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        
        
        int cnt = k;
        while(cnt && temp) {
            temp = temp->next;
            cnt--;
        }

        if(cnt>0) return head;

        ListNode* curr = head;
        ListNode* prev;
        ListNode* next;
        cnt = k;
        while(curr && cnt) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt--;
        }

        head->next = reverseKGroup(next,k);
        return prev;
    }
};


// Iterative using Stack
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        ListNode* curr = NULL, *start = NULL;

        while(temp) {
            int cnt = k;
            stack<int> st;
            while(cnt && temp) {
                st.push(temp->val);
                temp = temp->next;
                cnt--;
            }

            // we have k nodes hence reverse it
            if(cnt == 0) {
                while(!st.empty()) {
                    ListNode* newNode = new ListNode(st.top());
                    st.pop();
                    if(!start) {
                        start = newNode;
                        curr = newNode;
                    }
                    else {
                        curr->next = newNode;
                        curr = curr->next;
                    }
                }
            }
            else {
                stack<int> st2;
                while(!st.empty()) {
                    st2.push(st.top());
                    st.pop();
                }

                while(!st2.empty()) {
                    ListNode* newNode = new ListNode(st2.top());
                    st2.pop();
                    if(!start) {
                        start = newNode;
                        curr = newNode;
                    }
                    else {
                        curr->next = newNode;
                        curr = curr->next;
                    }
                }
            }
        }

        return start;
    }
};


// Noraml Iteerative
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int length = 0;

        // Calculate the length of the linked list
        while (head) {
            length++;
            head = head->next;
        }

        while (length >= k) {
            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }

            prev = curr;
            curr = curr->next;
            length -= k;
        }

        return dummy->next;
    }
};
