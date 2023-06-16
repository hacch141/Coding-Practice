// Largest Divisible Subset

class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastInd = 0;
        for(int idx=0; idx<n; idx++) {
            hash[idx] = idx;
            for(int prev=0; prev<=idx-1; prev++) {
                if(arr[idx]%arr[prev]==0 && 1+dp[prev]>dp[idx]) {
                    dp[idx] = 1 + dp[prev];
                    hash[idx] = prev;
                }
            }
            if(dp[idx] > dp[lastInd]) lastInd = idx;
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
