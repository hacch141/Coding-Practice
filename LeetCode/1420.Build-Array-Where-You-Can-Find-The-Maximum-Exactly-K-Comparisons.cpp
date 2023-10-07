// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

class Solution {
public:

    int mod = 1e9 + 7;

    int solve(int ind, int search_cost, int maxi, int& n, int& m, int& k, vector<vector<vector<int>>>& dp) {
        if(ind == n) {
            return search_cost == k;
        }

        if(dp[ind][search_cost][maxi] != -1) {
            return dp[ind][search_cost][maxi];
        }

        int cnt = 0;
        for(int i=1; i<=m; i++) {
            if(i > maxi) {
                cnt = (cnt + solve(ind+1 , search_cost+1 , i , n , m , k , dp)) % mod;
            }
            else {
                cnt = (cnt + solve(ind+1 , search_cost , maxi , n , m , k , dp)) % mod;
            }
        }

        return dp[ind][search_cost][maxi] = cnt;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(101,-1)));
        return solve(0,0,0,n,m,k,dp);
    }
};
