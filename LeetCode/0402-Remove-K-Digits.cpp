// 402. Remove K Digits

class Solution {
public:

    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        int s = 0;
        while(s < n && ans[s] == '0') s++;
        ans = ans.substr(s);
        
        return ans.length() == 0 ? "0" : ans;
    }
};
