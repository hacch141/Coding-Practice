class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int k = 0;
        for(int i=0; i<N; i++) k += arr[i];
        if(k%2 == 1) return false;
        vector<bool> dp(k+1,0), curr(k+1,0);
        dp[0] = curr[0] = true;
        if(arr[0] <= k) dp[arr[0]] = true;
        for(int i=1; i<N; i++) {
            for(int target = 1; target <= k; target++) {
                bool notpick = dp[target];
                bool pick = false;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                curr[target] = pick | notpick;
            }
            dp = curr;
        }
        return dp[k/2];
    }
};
