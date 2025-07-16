// 3201. Find the Maximum Length of Valid Subsequence I

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, evn = 0, alt = 1;
        bool prev_odd = nums[0] & 1;
        for(int i = 0; i < n; i++) {
            odd += nums[i] % 2 == 1;
            evn += nums[i] % 2 == 0;
            if((prev_odd && (nums[i] % 2 == 0)) || (!prev_odd && (nums[i] % 2 == 1))) {
                alt++;
                prev_odd = nums[i] & 1;
            }
        }
        return max({odd, evn, alt});
    }
};
