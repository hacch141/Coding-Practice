// 3065. Minimum Operations to Exceed Threshold Value I

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto i : nums) {
            ans += (i < k);
        }
        return ans;
    }
};
