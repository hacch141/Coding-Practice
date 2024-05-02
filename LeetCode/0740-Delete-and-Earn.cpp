// 740. Delete and Earn

class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums) mp[i]++;

        vector<int> v;
        for(auto i : mp) v.push_back(i.first);

        int n = v.size();
        vector<int> dp(n, 0);

        dp[0] = v[0] * mp[v[0]];
        if(n == 1) return dp[0];

        dp[1] = v[1] * mp[v[1]] + ((v[1] != v[0] + 1) ? dp[0] : 0);
        dp[1] = max(dp[1], dp[0]);

        for(int i = 2; i < n; i++) {
            int e = v[i];
            int curr = e * mp[e] + ((v[i] != v[i - 1] + 1) ? dp[i - 1] : dp[i - 2]);
            dp[i] = max(curr, dp[i - 1]);
        }
        return dp[n - 1];
    }
};
