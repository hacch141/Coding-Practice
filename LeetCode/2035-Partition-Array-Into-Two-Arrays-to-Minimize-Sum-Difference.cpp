// 2035. Partition Array Into Two Arrays to Minimize Sum Difference

class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), ans = INT_MAX, sum = 0;
        for(auto i : nums) sum += i;

        int n = N / 2;
        vector<vector<int>> left(n + 1), right(n + 1);

        for(int mask = 0; mask < (1 << n); mask++) {
            int s1 = 0, s2 = 0, sz = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    s1 += nums[i];
                    s2 += nums[i + n];
                    sz++;
                }
            }
            left[sz].push_back(s1);
            right[sz].push_back(s2);
        }

        for(int sz = 1; sz <= n; sz++) sort(right[sz].begin(), right[sz].end());

        for(int lsz = 1; lsz <= n; lsz ++) {
            for(auto &a : left[lsz]) {
                int b = (sum - (2 * a)) / 2, rsz = n - lsz;
                auto& v = right[rsz];
                auto it = lower_bound(v.begin(), v.end(), b);
                if(it != v.end()) ans = min(ans, abs(sum - 2 * (a + *(it))) );
                if(it != v.begin()) {
                    it--;
                    ans = min(ans, abs(sum - 2 * (a + *(it))) );
                }
            }
        }

        return ans;
    }
};
