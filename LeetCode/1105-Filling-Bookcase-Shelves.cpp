// 1105. Filling Bookcase Shelves

class Solution {
public:
    int solve(int ind, int n, vector<vector<int>>& books, int shelfWidth, vector<int>& dp) {
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int mx_height = 0, curr_width = 0;
        int ans = INT_MAX;
        for(int i = ind; i < n; i++) {
            mx_height = max(mx_height, books[i][1]);
            curr_width += books[i][0];
            if(curr_width > shelfWidth) break;
            ans = min(ans, mx_height + solve(i + 1, n, books, shelfWidth, dp));
        }
        return dp[ind] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        return solve(0, n, books, shelfWidth, dp);
    }
};
