// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        sort(strs.begin(),strs.end());
        int size = min(strs[0].length(),strs[n-1].length());

        int ptr = 0;
        string ans = "";

        while(ptr<size && strs[0][ptr] == strs[n-1][ptr]) {
            ans += strs[0][ptr];
            ptr++;
        }

        return ans;
    }
};
