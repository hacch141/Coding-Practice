// 2419. Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 1, cnt = 0;
        for(auto i : nums) {
            if(i == mx) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
