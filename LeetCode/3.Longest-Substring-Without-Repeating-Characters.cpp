// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = s.length();
        while(right < n) {
            if(mpp[s[right]] != -1) {
                left = max(mpp[s[right]]+1,left);
            }
            mpp[s[right]] = right;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
