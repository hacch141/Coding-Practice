// Recursion
class Solution{
    
  private:
    bool solve(int i, int j, string& pattern, string& str) {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0) {
            while(i>=0) {
                if(str[i--] != '*') return false;
            }
            return true;
        }
        if(pattern[i] == str[j] || pattern[i] == '?') {
            return solve(i-1,j-1,pattern,str);
        }
        else if(pattern[i] == '*'){
            return solve(i,j-1,pattern,str) | solve(i-1,j,pattern,str);
        }
        return false;
    }
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        
        return solve(n-1,m-1,pattern,str);
    }
};



// Memoization
class Solution{
    
  private:
    bool solve(int i, int j, string& pattern, string& str, vector<vector<int>>& dp) {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0) {
            while(i>=0) {
                if(pattern[i--] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(pattern[i] == str[j] || pattern[i] == '?') {
            return dp[i][j] = solve(i-1,j-1,pattern,str,dp);
        }
        else if(pattern[i] == '*'){
            return dp[i][j] = solve(i-1,j,pattern,str,dp) | solve(i,j-1,pattern,str,dp);
        }
        return dp[i][j] = false;
    }
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return solve(n-1,m-1,pattern,str,dp);
    }
};



// Tabulation
class Solution{
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        
        dp[0][0] = true;
        
        for(int j=1; j<=m; j++) {
            dp[0][j] = false;
        }
        
        for(int i=1; i<=n; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(pattern[k-1] != '*') flag = false;
            }
            dp[i][0] = flag;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};



// space optimization
class Solution{
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<bool> dp(m+1,false), curr(m+1,false);
        
        dp[0] = true;
        
        for(int j=1; j<=m; j++) {
            dp[j] = false;
        }
        
        for(int i=1; i<=n; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(pattern[k-1] != '*') flag = false;
            }
            curr[0] = flag;
            for(int j=1; j<=m; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    curr[j] = dp[j-1];
                }
                else if(pattern[i-1] == '*') {
                    curr[j] = dp[j] | curr[j-1];
                }
                else {
                    curr[j] = false;
                }
            }
            dp = curr;
        }
        
        return dp[m];
    }
};
