// 1190. Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(ch == ')') {
                string tmp;
                while(!st.empty() && st.top() != '(') {
                    tmp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(auto t : tmp) {
                    st.push(t);
                }
            }
            else {
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
