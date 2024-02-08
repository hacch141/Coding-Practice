// 279. Perfect Squares

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
