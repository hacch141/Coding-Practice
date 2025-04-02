// 2873. Maximum Value of an Ordered Triplet I

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> l_mx(n, 0), r_mx(n, 0);

        l_mx[0] = nums[0];
        for(int i = 1; i < n; i++) {
            l_mx[i] = max(l_mx[i - 1], (long long)nums[i]);
        }

        r_mx[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            r_mx[i] = max(r_mx[i + 1], (long long)nums[i]);
        }

        long long ans = 0;
        for(int i = 1; i < n - 1; i++) {
            ans = max(ans, (l_mx[i - 1] - nums[i]) * r_mx[i + 1]);
        }

        return ans;
    }
};
