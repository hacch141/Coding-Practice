// 2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), mx = 0, ans = 0;
        for(auto i : nums) mx |= i;
        for(int i = 0; i < (1 << n); i++) {
            int _or = 0;
            for(int j = 0; j < 32; j++) {
                if(1 & (i >> j)) {
                    _or |= nums[j];
                }
            }
            ans += mx == _or;
        }
        return ans;
    }
};

// Rec
class Solution {
public:
    int solve(int ind, int n, vector<int>& nums, int curr, int mx, map<pair<int,int>,int>& mp) {
        if(ind == n) return curr == mx;
        if(mp.count({ind, curr})) return mp[{ind, curr}];
        int take = solve(ind + 1, n, nums, curr | nums[ind], mx, mp);
        int nottake = solve(ind + 1, n, nums, curr, mx, mp);
        return mp[{ind, curr}] = take + nottake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        for(auto i : nums) mx |= i;
        int n = nums.size();
        map<pair<int,int>,int> mp;
        return solve(0, n, nums, 0, mx, mp);
    }
};
