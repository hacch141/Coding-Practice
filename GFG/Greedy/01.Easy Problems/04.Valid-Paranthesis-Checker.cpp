// Valid Paranthesis Checker

#include <bits/stdc++.h>

bool isBalanced(string S){
    // Write your code here.
    stack<char> st;
    for(auto i : S) {
        if(i=='(' || i=='{' || i=='[') {
            st.push(i);
        }
        else {
            
            if(st.empty()) return false;
            char prev = st.top();
            st.pop();

            if (i == ')') {
              if (prev != '(') return false;
            } 
            else if (i == '}') {
              if (prev !='{') return false;
            }
            else if (i == ']') {
              if (prev !='[') return false;
            }
        }
    }

    return true;
}
// T : O(N)
// S : O(N)
