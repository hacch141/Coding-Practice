// Printing Longest Increasing Subsequence

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1), hash(n);
        int lastInd = 0;
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<=i-1; prev++) {
                if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > dp[lastInd]) lastInd = i;
        }
        
        vector<int> ans;
        ans.push_back(arr[lastInd]);
        while(hash[lastInd] != lastInd) {
            lastInd = hash[lastInd];
            ans.push_back(arr[lastInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
