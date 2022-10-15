// 1249. Minimum Remove to Make Valid Parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty() == false && s[st.top()] == '(') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }
        while(st.empty() == false) {
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};
