// 2971. Find Polygon With the Largest Perimeter

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> pref(n, 0);
        pref[0] = nums[0];

        long long ans = -1;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            if(i > 1 && pref[i - 1] > nums[i]) ans = max(ans, pref[i]);
        }

        return ans;
    }
};
