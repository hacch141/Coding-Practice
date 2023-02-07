// Recursion
class Solution {
    
private:
    int solve(int i, int j, vector<int> &arr) {
        if(i>j) return 0;
        
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int coins = arr[i-1]*arr[k]*arr[j+1] + solve(i,k-1,arr) + solve(k+1,j,arr);
            maxi = max(maxi,coins);
        }
        return maxi;
    }
    
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        return solve(1,N,arr);
    }
};



// Memoization
class Solution {
    
private:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>>& dp) {
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int coins = arr[i-1]*arr[k]*arr[j+1] + solve(i,k-1,arr,dp) + solve(k+1,j,arr,dp);
            maxi = max(maxi,coins);
        }
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp(N+1, vector<int> (N+1,-1));
        return solve(1,N,arr,dp);
    }
};



// Tabulation
class Solution {
    
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp(N+2, vector<int> (N+2,0));
        
        for(int i=N; i>=1; i--) {
            for(int j=1; j<=N; j++) {
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int k=i; k<=j; k++) {
                    int coins = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][N];
    }
};
