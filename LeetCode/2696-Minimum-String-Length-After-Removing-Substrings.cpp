// 2696. Minimum String Length After Removing Substrings

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(ch == 'B' && !st.empty() && st.top() == 'A') st.pop();
            else if(ch == 'D' && !st.empty() && st.top() == 'C') st.pop();
            else st.push(ch);
        }
        return st.size();
    }
};
