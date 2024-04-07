// 678. Valid Parenthesis String

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st, star;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '*') {
                star.push(i);
            }
            else if(ch == '(') {
                st.push(i);
            }
            else {
                if(!st.empty()) {
                    st.pop();
                }
                else if(!star.empty() > 0 ) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }

        while(!st.empty() && !star.empty()) {
            if(st.top() < star.top()) {
                st.pop();
                star.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};
