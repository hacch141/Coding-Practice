// 2302. Count Subarrays With Score Less Than K

class Solution {
public:
    bool ok(int l, int r, vector<long long>& prefix, long long k) {
        return (prefix[r] - (l > 0 ? prefix[l - 1] : 0)) * (r - l + 1) < k;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1] + nums[i];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long l = i, h = n - 1, lst = -1;
            while(l <= h) {
                long long m = (h - l) / 2 + l;
                if(ok(i, m, prefix, k)) {
                    l = m + 1;
                    lst = m;
                }
                else {
                    h = m - 1;
                }
            }
            if(lst != -1) ans += lst - i + 1;
        }

        return ans;
    }
};
