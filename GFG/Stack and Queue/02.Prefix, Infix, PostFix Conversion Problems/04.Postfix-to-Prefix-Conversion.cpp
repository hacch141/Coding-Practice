// Postfix to Prefix Conversion
// ABC/-AK/L-* -> *-A/BC-/AKL

class Solution {

    public static String postfixToPrefix(String exp) {

        Stack<String> stack = new Stack<>();

        // scan left to right
        for (int i = 0; i < exp.length(); i++) {

            char ch = exp.charAt(i);

            // if operand
            if (Character.isLetterOrDigit(ch)) {
                stack.push(ch + "");
            }

            // if operator
            else {
                String op2 = stack.pop();
                String op1 = stack.pop();

                String temp = ch + op1 + op2;
                stack.push(temp);
            }
        }

        return stack.pop();
    }
}

// =====================================================================

#include <bits/stdc++.h>

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

string postfixToPrefix(string &s){
    // Write your code here.
    stack<string> st;

    for(auto i : s) {
        if(isOperator(i)) {
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();

            st.push(i + a + b);
        }
        else {
            st.push(string(1,i));
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
    ans += head->data;
    helper(head->left,ans);
    helper(head->right,ans);
}

string postfixToPrefix(string &s){
    // Write your code here.
    stack<Node*> st;

    for(auto i : s) {
        if(isOperator(i)) {
            Node* b = st.top();
            st.pop();
            Node* a = st.top();
            st.pop();

            Node* newHead = new Node(i);
            newHead->left = a;
            newHead->right = b;

            st.push(newHead);
        }
        else {
            Node* a = new Node(i);
            st.push(a);
        }
    }

    string ans;
    helper(st.top(),ans);

    return ans;
}
// T : O(N)
// S : O(N)
