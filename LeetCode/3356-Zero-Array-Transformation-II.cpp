// 3356. Zero Array Transformation II

class Solution {
public:
    bool ok(int mid, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        for(int i = 0; i < mid; i++) {
            f[queries[i][0]] += queries[i][2];
            f[queries[i][1] + 1] -= queries[i][2];
        }

        for(int i = 1; i < n; i++) {
            f[i] += f[i - 1];
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] > f[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int low = 0 , high = queries.size(), ans = -1;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(mid, nums, queries)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
