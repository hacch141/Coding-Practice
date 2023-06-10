// Longest Palindromic Subsequence

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(),B.end());
        int m = A.length();
        vector<int> dp(m+1,0), curr(m+1,0);
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=m; j++) {
                if(A[i-1] == B[j-1]) {
                    curr[j] = 1 + dp[j-1];
                }
                else {
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return dp[m];
    }
};
