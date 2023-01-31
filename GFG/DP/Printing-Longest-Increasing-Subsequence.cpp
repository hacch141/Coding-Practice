class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1), hash(n);
        int maxi = 1;
        int lastidx = 0;
        
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<i; prev++) {
                if(arr[prev] < arr[i] && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastidx = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[lastidx]);
        while(hash[lastidx] != lastidx) {
            lastidx = hash[lastidx];
            ans.push_back(arr[lastidx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
