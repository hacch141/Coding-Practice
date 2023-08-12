// Check if there exists a subsequence with sum K

bool solve(int i, int& n, int& sum, vector<int>& a, vector<vector<int>>& dp) {
    if(i == n) {
        return sum == 0 ? true : false;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    bool nottake = solve(i+1,n,sum,a,dp);

    bool take = false;
    if(a[i] <= sum) {
        sum -= a[i];
        take = solve(i+1,n,sum,a,dp);
        sum += a[i];
    }
    return dp[i][sum] = take | nottake;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return solve(0,n,k,a,dp);
}

// T : O(n*k)
// S : O(n*k + STACK)
