// 3193. Count the Number of Inversions

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve(int prefi, int j, int cnt, vector<vector<int>>& req, vector<vector<int>>& dp) {

        if(j >= 0 && prefi == req[j][0]) {
            if(cnt != req[j][1]) return 0;
            j--;
        }

        if(prefi == 0) {
            return cnt == 0;
        }
        
        if(dp[prefi][cnt] != -1) return dp[prefi][cnt];

        int ans = 0;
        for(int c = 0; c <= min(cnt, prefi); c++) {
            ans = (ans + solve(prefi - 1, j, cnt - c, req, dp)) % MOD;
        }
        return dp[prefi][cnt] = ans;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        sort(requirements.begin(), requirements.end());
        vector<vector<int>> dp(n + 1, vector<int>(401, -1));
        return solve(n - 1, requirements.size() - 1, requirements.back()[1],  requirements, dp);
    }
};
