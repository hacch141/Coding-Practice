// 279. Perfect Squares

// rec
class Solution {
public:
    int dp[100001];

    int solve(int n) {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];

        int curr = INT_MAX;
        for(int i = 1; i * i <= n; i++) {
            curr = min(curr, 1 + solve(n - (i * i)));
        }

        return dp[n] = curr;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

// dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        if(sq * sq == n) {
            return 1;
        }

        int num = n;
        while(num % 4 == 0) num /= 4;
        if(num % 8 == 7) return 4;

        for(int i = 1; i * i <= n; i++) {
            int ele = n - (i * i);
            int sq = sqrt(ele);
            if(sq * sq == ele) {
                return 2;
            }
        }

        return 3;
    }
};
