// 3355. Zero Array Transformation I

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n, 0);
        for(auto& i : queries) {
            f[i[0]]++;
            if(i[1] + 1 < n) f[i[1] + 1]--;
        }

        for(int i = 1; i < n; i++) f[i] += f[i - 1];

        for(int i = 0; i < n; i++) {
            if(nums[i] > f[i]) return false;
        }

        return true;
    }
};
