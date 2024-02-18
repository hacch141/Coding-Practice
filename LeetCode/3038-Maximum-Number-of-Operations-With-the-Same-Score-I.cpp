// 3038. Maximum Number of Operations With the Same Score I

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int prev = nums[0] + nums[1], ans = 1;
        for(int i = 2; i < nums.size() - 1; i += 2) {
            int curr = nums[i] + nums[i + 1];
            if(prev == curr) ans++;
            else break;
        }
        return ans;
    }
};
