// 368. Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> cnt(n, 1), prev(n);
        for(int i = 0; i < n; i++) prev[i] = i;

        int mx = 0, mx_ind = -1;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] % nums[i] == 0 && cnt[j] < 1 + cnt[i]) {
                    cnt[j] = 1 + cnt[i];
                    prev[j] = i;
                }
            }
            if(cnt[i] > mx) {
                mx = cnt[i];
                mx_ind = i;
            }
        }

        vector<int> ans;
        while(prev[mx_ind] != mx_ind) {
            ans.push_back(nums[mx_ind]);
            mx_ind = prev[mx_ind];
        }
        ans.push_back(nums[mx_ind]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
