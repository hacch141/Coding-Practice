// 3152. Special Array II

class Solution {
public:
    bool isParity(int a, int b) {
        return (a & 1) != (b & 1);
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n, 0);
        for(int i = 1; i < n; i++) {
            if(isParity(nums[i - 1], nums[i])) {
                f[i] += (f[i - 1] + 1);
            }
        }
        vector<bool> ans;
        for(auto q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(f[r] >= r - l);
        }
        return ans;
    }
};
