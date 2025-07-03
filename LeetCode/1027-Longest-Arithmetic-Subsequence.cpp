// 1027. Longest Arithmetic Subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> mp(n);
        int ans = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[j] - nums[i];
                if(mp[j].count(diff)) {
                    mp[i][diff] = 1 + mp[j][diff];
                }
                else {
                    mp[i][diff] = 2;
                }
                ans = max(ans, mp[i][diff]);
            }
        }
        return ans;
    }
};
