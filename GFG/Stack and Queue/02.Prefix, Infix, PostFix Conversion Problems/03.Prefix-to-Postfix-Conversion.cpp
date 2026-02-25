// Prefix to Postfix Conversion
// *-A/BC-/AKL -> ABC/-AK/L-*

class Solution {
    public static String prefixToPostfix(String exp) {

        Stack<String> stack = new Stack<>();

        for (int i = exp.length() - 1; i >= 0; i--) {

            char ch = exp.charAt(i);

            // operand
            if (Character.isLetterOrDigit(ch)) {
                stack.push(ch + "");
            }

            // operator
            else {
                String op1 = stack.pop();
                String op2 = stack.pop();

                stack.push(op1 + op2 + ch);
            }
        }

        return stack.pop();
    }
}

// =============================================================================

#include <bits/stdc++.h>

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

string preToPost(string s) {
    // Write Your Code Here
    int n = s.length();
    stack<string> st;

    for(int i=n-1; i>=0; i--) {
        if(isOperator(s[i])) {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            st.push(a + b + s[i]);
        }
        else {
            st.push(string(1,s[i]));
        }
    }

    return st.top();
}
// T : O(N)
// S : O(N)



#include <bits/stdc++.h>

class Node {
    public:
    char data;
    Node *left, *right;
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

void helper(Node*& head, string& ans) {
    if(!head) return;
    helper(head->left,ans);
    helper(head->right,ans);
    ans += head->data;
}

string preToPost(string s) {
    // Write Your Code Here
    int n = s.length();
    stack<Node*> st;

    for(int i=n-1; i>=0; i--) {
        if(isOperator(s[i])) {
            Node* a = st.top();
            st.pop();
            Node* b = st.top();
            st.pop();

            Node* newHead = new Node(s[i]);
            newHead->left = a;
            newHead->right = b;
            st.push(newHead);
        }
        else {
            Node* a = new Node(s[i]);
            st.push(a);
        }
    }

    string ans;
    helper(st.top(),ans);

    return ans;
}
// T : O(N)
// S : O(N)
