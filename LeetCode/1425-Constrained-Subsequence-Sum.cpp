// 1425. Constrained Subsequence Sum

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 0);

        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            dp[i] = nums[i];

            while(!pq.empty() && (i - pq.top().second > k)) pq.pop();
            if(!pq.empty()) dp[i] = max(dp[i], nums[i] + pq.top().first);

            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        if(ans == 0) ans = *max_element(nums.begin(), nums.end());
        return ans;
    }
};
