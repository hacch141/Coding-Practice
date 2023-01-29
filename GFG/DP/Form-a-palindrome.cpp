class Solution{
  public:
    int countMin(string str){
        //complete the function here
        int m = str.length();
        string str2 = str;
        reverse(str2.begin(),str2.end());
        vector<int> dp(m+1,0), curr(m+1,0);
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=m; j++) {
                if(str[i-1] == str2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                }
                else {
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return m-dp[m];
    }
};
