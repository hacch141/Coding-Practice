// gives TLE
class Solution
{
    
    private:
        void solve(int x, int y, vector<vector<int>> dp, string s, string t, string curr, set<string>& st, vector<string>& ans) {
            if(x==0 || y==0) {
                if(curr != "") {
                    reverse(curr.begin(),curr.end());
                    if(st.count(curr) == 0){
                        st.insert(curr);
                        ans.push_back(curr);
                    }
                }
                return;
            }
            if(s[x-1] == t[y-1]) {
                curr += s[x-1];
                solve(x-1,y-1,dp,s,t,curr,st,ans);
            }
            else if(dp[x-1][y] > dp[x][y-1]) {
                solve(x-1,y,dp,s,t,curr,st,ans);
            }
            else if(dp[x-1][y] < dp[x][y-1]){
                solve(x,y-1,dp,s,t,curr,st,ans);
            } 
            else {
                solve(x-1,y,dp,s,t,curr,st,ans);
                solve(x,y-1,dp,s,t,curr,st,ans);
            }
        }
        
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int n = s.length();
		    int m = t.length();
		    vector<vector<int>> dp(n+1, vector<int> (m+1,0));
		    
		    for(int i=1; i<=n; i++) {
		        for(int j=1; j<=m; j++) {
		            if(s[i-1] == t[j-1]) {
		                dp[i][j] = 1 + dp[i-1][j-1];
		            } else {
		                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		            }
		        }
		    }
		    
		    set<string> st;
		    vector<string> ans;
		    string curr = "";
		    solve(n+1,m+1,dp,s,t,curr,st,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
