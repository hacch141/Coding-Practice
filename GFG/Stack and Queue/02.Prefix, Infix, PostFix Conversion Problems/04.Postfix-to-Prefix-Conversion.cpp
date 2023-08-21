// Postfix to Prefix Conversion

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
