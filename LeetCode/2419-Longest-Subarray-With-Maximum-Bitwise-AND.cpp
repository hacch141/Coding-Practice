// 2419. Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = INT_MIN, ans = 0;
        for(auto i : nums) mx = max(mx, i);
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == mx) cnt++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
