// 20. Valid Parentheses

class Solution {
public:
    
    bool matching(char a, char b) {
        return (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')');
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) {
                    return false;
                }
                else if(matching(st.top(),s[i]) == false) {
                    return false;
                }
            st.pop();
            }
        }
        return st.empty();
    }
};
