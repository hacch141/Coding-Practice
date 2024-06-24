// 995. Minimum Number of K Consecutive Bit Flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flips = 0, curr = 0;
        vector<int> add(n + 1, 0);
        for(int i = 0; i < n - k + 1; i++) {
            curr += add[i];
            if((curr % 2 == 0 && nums[i] == 0) || (curr % 2 == 1 && nums[i] == 1)) {
                curr++;
                flips++;
                add[i + k]--;
            }
        }
        for(int i = n - k + 1; i < n; i++) {
            curr += add[i];
            if((curr % 2 == 0 && nums[i] == 0) || (curr % 2 == 1 && nums[i] == 1)) {
                return -1;
            }
        }
        return flips;
    }
};
