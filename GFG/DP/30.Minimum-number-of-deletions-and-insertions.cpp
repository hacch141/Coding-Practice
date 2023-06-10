// Minimum number of deletions and insertions

class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    vector<int> dp(m+1,0), curr(m+1,0);
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=m; j++) {
	            if(str1[i-1] == str2[j-1]) {
	                curr[j] = 1 + dp[j-1];
	            }
	            else {
	                curr[j] = max(curr[j-1],dp[j]);
	            }
	        }
	        dp = curr;
	    }
	    return n+m-(2*dp[m]);
	} 
};
