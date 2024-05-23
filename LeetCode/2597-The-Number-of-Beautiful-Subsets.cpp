// 2597. The Number of Beautiful Subsets

class Solution {
public:

    int solve(int index, vector<int>& nums, int k, vector<int> &cnt) {
        
        if(index == nums.size()) return 1;
        
        int nottake = solve(index + 1, nums, k, cnt), take = 0;
        int num = nums[index];

        if((num + k > 1000 || cnt[num + k] == 0) && (num - k < 1 || cnt[num - k] == 0)) {
            cnt[num]++;
            take = solve(index + 1, nums, k, cnt);
            cnt[num]--;
        }

        return take + nottake;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> cnt(1001, 0);
        return solve(0, nums, k, cnt) - 1;
    }
};
