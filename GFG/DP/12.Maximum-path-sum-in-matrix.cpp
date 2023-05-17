// Maximum path sum in matrix

// Memoization
class Solution{
public:

    int solve(int i, int j, int& N, vector<vector<int>>& Matrix, vector<vector<int>>& dp) {
        if(j<0 || j>=N) return -1e9;
        if(i==N-1) return Matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = Matrix[i][j] + solve(i+1,j-1,N,Matrix,dp);
        int down = Matrix[i][j] + solve(i+1,j,N,Matrix,dp);
        int right = Matrix[i][j] + solve(i+1,j+1,N,Matrix,dp);
        
        return dp[i][j] = max(left,max(down,right));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int> (N,-1));
        int ans = INT_MIN;
        for(int i=0; i<N; i++) {
            ans = max(ans,solve(0,i,N,Matrix,dp));
        }
        return ans;
        // code here
    }
};
// T : O(N*N)
// S : O(N*N) + STACK


// ======================================================================================


// Tabulation
class Solution{
public:

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int> (N,-1));
        int ans = INT_MIN;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                
                if(i==0) {
                    dp[i][j] = Matrix[i][j];
                }
                else {
                    int leftdg=-1e9, down=-1e9, rightdg=-1e9;
                    if(j-1>=0) leftdg = Matrix[i][j] + dp[i-1][j-1];
                    down = Matrix[i][j] + dp[i-1][j];
                    if(j+1<N) rightdg = Matrix[i][j] + dp[i-1][j+1];
                    
                    dp[i][j] = max(leftdg, max(down,rightdg));
                }
                
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
// T : O(N*N)
// S : O(N*N)


// ======================================================================================


// Space Optimization
class Solution{
public:

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> prev(N,-1), curr(N,-1);
        int ans = INT_MIN;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                
                if(i==0) {
                    curr[j] = Matrix[i][j];
                }
                else {
                    int leftdg=-1e9, down=-1e9, rightdg=-1e9;
                    if(j-1>=0) leftdg = Matrix[i][j] + prev[j-1];
                    down = Matrix[i][j] + prev[j];
                    if(j+1<N) rightdg = Matrix[i][j] + prev[j+1];
                    
                    curr[j] = max(leftdg, max(down,rightdg));
                }
                
                ans = max(ans,curr[j]);
            }
            prev = curr;
        }
        return ans;
    }
};
// T : O(N*N)
// S : O(N)
