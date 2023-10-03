// 316. Remove Duplicate Letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> check(26, false);

        for (auto i : s) freq[i - 'a']++;

        stack<char> st;
        for(auto ch : s) {
            freq[ch-'a']--;
            if(check[ch-'a']) continue;

            while(!st.empty() && ch < st.top() && freq[st.top()-'a']>0) {
                check[st.top()-'a'] = 0;
                st.pop();
            }

            st.push(ch);
            check[ch-'a'] = 1;
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
