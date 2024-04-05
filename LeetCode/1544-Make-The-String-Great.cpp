// 1544. Make The String Great

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(!st.empty()) {
                if(st.top() - 'a' == ch - 'A' || st.top() - 'A' == ch - 'a') {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }

        string ans = "";
        while(!st.empty()) ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
