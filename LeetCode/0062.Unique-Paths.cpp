// 62. Unique Paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m,0);
        for(int i=n-1; i>=0; i--) {
            vector<int> curr(m,0);
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 && j==m-1) curr[j] = 1;
                else {
                    int right = 0;
                    int down = 0;
                    if(i<n-1) down = dp[j];
                    if(j<m-1) right = curr[j+1];
                    curr[j] = right + down;
                }
            }
            dp = curr;
        }
        return dp[0];
    }
};

// ======================================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m,0);
        for(int i=0; i<n; i++) {
            vector<int> curr(m,0);
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) curr[j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            dp = curr;
        }
        return dp[m-1];
    }
};
