// 446. Arithmetic Slices II - Subsequence

#define ll long long

class Solution {
public:

    // int solve(int prev, ll& diff, vector<int>& nums, unordered_map<int,vector<int>>& mp, vector<int>& dp) {

    //     if(dp[prev] != -1) return dp[prev];

    //     int take = 0;
    //     ll next = (ll)nums[prev] + diff;

    //     if(!(INT_MIN <= next && next <= INT_MAX)) return 0;

    //     if(mp.find(next) != mp.end()) {
    //         vector<int> v = mp[next];
    //         for(auto i : v) {
    //             if(i > prev) {
    //                 take += (1 + solve(i, diff, nums, mp, dp));
    //             }
    //         }
    //     }
    //     return dp[prev] = take;
    // }

    int numberOfArithmeticSlices(vector<int>& nums) {
        
        // int ans = 0, n = nums.size();
        // if(n < 3) return 0;

        // unordered_map<int,vector<int>> mp;
        // for(int i=0; i<n; i++) mp[nums[i]].push_back(i);

        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         ll diff = (ll)nums[j]-nums[i];
        //         vector<int> dp(n+1, -1);
        //         ans += solve(j, diff, nums, mp, dp);
        //     }
        // }
        // return ans;

        int n = nums.size(), ans = 0;
        vector<unordered_map<ll,int>> dp(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ll diff = (ll)nums[j] - nums[i];
                dp[j][diff] += (1 + dp[i][diff]);
                ans += dp[i][diff];
            }
        }

        return ans;
    }
};
