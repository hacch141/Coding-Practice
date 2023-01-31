class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = INT_MIN;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
