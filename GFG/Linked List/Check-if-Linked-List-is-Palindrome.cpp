// Check if Linked List is Palindrome

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
  
      bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL) {
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* curr = slow->next;
        Node* prev = NULL;
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node* curr1 = head;
        Node* curr2 = prev;
        
        while(curr2 != NULL) {
            if(curr1->data != curr2->data) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
  
//     bool isPalindrome(Node *head)  //  2nd Method
//     {
//         //Your code here
//         stack<int> st;
//         Node* curr = head;
//         while(curr != NULL) {
//             st.push(curr->data);
//             curr = curr->next;
//         }
        
//         curr = head;
//         while(curr != NULL) {
//             if(curr->data != st.top()) {
//                 return false;
//             }
//             st.pop();
//             curr = curr->next;
//         }
//         return true;
//     }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends