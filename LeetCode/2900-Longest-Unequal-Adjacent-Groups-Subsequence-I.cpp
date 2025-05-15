// 2900. Longest Unequal Adjacent Groups Subsequence I

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        ans.push_back(words[0]);
        int lst = 0;
        for(int i = 1; i < words.size(); i++) {
            if(groups[i] != groups[lst]) {
                ans.push_back(words[i]);
                lst = i;
            }
        }
        return ans;
    }
};
