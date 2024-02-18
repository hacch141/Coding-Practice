// 3043. Find the Length of the Longest Common Prefix

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), ans = 0;
        unordered_set<string> st;
        for(int i = 0; i < m; i++) {
            string s = "", str = to_string(arr2[i]);
            for(auto ch : str) {
                s += ch;
                st.insert(s);
            }
        }

        for(int i = 0; i < n; i++) {
            string s = "", str = to_string(arr1[i]);
            for(auto ch : str) {
                s += ch;
                if(st.count(s)) {
                    ans = max(ans, (int)s.length());
                }
            }
        }
        return ans;
    }
};
