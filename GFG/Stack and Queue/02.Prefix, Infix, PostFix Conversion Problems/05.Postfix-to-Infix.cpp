// Postfix to Infix

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
