// Postfix to Infix
// ABC/-AK/L-* -> ((A-(B/C))*((A/K)-L))

class Solution {

    public static String postfixToInfix(String exp) {

        Stack<String> stack = new Stack<>();

        // scan left to right
        for (int i = 0; i < exp.length(); i++) {

            char ch = exp.charAt(i);

            // operand
            if (Character.isLetterOrDigit(ch)) {
                stack.push(ch + "");
            }

            // operator
            else {
                String op2 = stack.pop();
                String op1 = stack.pop();

                String temp = "(" + op1 + ch + op2 + ")";
                stack.push(temp);
            }
        }

        return stack.pop();
    }
}

// ========================================================================

#include <bits/stdc++.h>

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

string postToInfix(string postfix) {
    // Write your code here.
    int n = postfix.length();
    stack<string> st;

    for(int i=0; i<n; i++) {
        if(isOperator(postfix[i])) {
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            st.push('(' + a + postfix[i] + b + ')');
        }
        else {
            st.push(string(1,postfix[i]));
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
	ans += '(';
	helper(head->left,ans);
	ans.pop_back();
	ans += head->data;
	helper(head->right,ans);
	ans += ')';
}

string postToInfix(string postfix) {
    // Write your code here.
    int n = postfix.length();
	stack<Node*> st;

    for(int i=0; i<n; i++) {
        if(isOperator(postfix[i])) {
            Node* b = st.top();
            st.pop();
            Node* a = st.top();
            st.pop();

            Node* newHead = new Node(postfix[i]);
            newHead->left = a;
            newHead->right = b;

            st.push(newHead);
        }
        else {
            Node* a = new Node(postfix[i]);
            st.push(a);
        }
    }

    string ans;
	helper(st.top(),ans);
	ans.resize(ans.size()-1);

	return ans;
}
// T : O(N)
// S : O(N)
