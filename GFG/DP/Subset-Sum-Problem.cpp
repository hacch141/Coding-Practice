class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<bool> dp(sum+1,0), curr(sum+1,0);
        dp[0] = curr[0] = true;
        if(arr[0] <= sum) dp[arr[0]] = true;
        for(int i=1; i<n; i++) {
            for(int target=1; target<=sum; target++) {
                bool notpick = dp[target];
                bool pick = false;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                curr[target] = notpick | pick;
            }
            dp = curr;
        }
        return dp[sum];
    }
};
