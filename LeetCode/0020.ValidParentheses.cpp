// 20. Valid Parentheses

class Solution {
public:

    bool isMatch(stack<char>& st, char& curr) {
        return !st.empty() && ((curr=='}' && st.top()=='{') || (curr==']' && st.top()=='[') || (curr==')' && st.top()=='(')) ? true : false;
    }

    bool isValid(string s) {

        stack<char> st;
        int n = s.length();

        for(int i=0; i<n; i++) {

            if(s[i]=='{' || s[i]=='[' || s[i]=='(') {
                st.push(s[i]);
            }
            
            else {
                if(isMatch(st,s[i])) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};
