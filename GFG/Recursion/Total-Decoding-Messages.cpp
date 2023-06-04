// Total Decoding Messages

class Solution {
	public:
	
	int mod = 1e9+7;
	
	int solve(int idx, int n, string str, vector<int>& dp) {
	    
	    if(idx==n) {
	        return 1;
	    }
	    
	    if(dp[idx] != -1) return dp[idx];
    
      if(str[idx]=='0') {
	        return 0;
	    }
	    
	    int takeOne = 0;
	    int takeTwo = 0;   
	    
	    if(idx+1<n) {
	        
	        string twos = str.substr(idx,2);
	        int num = ((twos[0]-'0')*10) + (twos[1]-'0');
	        if(num >= 10 && num <= 26) {
	            takeTwo = solve(idx+2,n,str,dp);
	        }
	        
	    }
	    
	    takeOne = solve(idx+1,n,str,dp);
	    
	    return dp[idx] = (takeOne+takeTwo)%mod;
	}
	
	int CountWays(string str) {
	    // Code here
	    int n = str.length();
	    vector<int> dp(n,-1);
	    return solve(0,n,str,dp);
	}
};

// T : O(N)
// S : O(N)
