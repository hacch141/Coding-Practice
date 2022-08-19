// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if(n == 0) {
            return ans;
        }
        sort(strs.begin(),strs.end());
        for(int i=0; i<strs[0].size(); i++) {
            if(strs[0][i] == strs[n-1][i]) {
                ans += strs[0][i];
            }
            else {
                break;
            }
        }
        return ans;
    }
};
