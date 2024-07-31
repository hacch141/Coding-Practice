// 1105. Filling Bookcase Shelves
class Solution {
public:

    int solve(int ind, int& n, vector<vector<int>>& books, int shelfWidth, vector<int>& dp) {
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int currwidth = 0, mx = 0, ans = INT_MAX;
        for(int i = ind; i < n; i++) {
            currwidth += books[i][0];
            mx = max(mx, books[i][1]);
            if(currwidth > shelfWidth) break;
            ans = min(ans, mx + solve(i + 1, n, books, shelfWidth, dp));
        }
        return dp[ind] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        return solve(0, n, books, shelfWidth, dp);
    }
};
