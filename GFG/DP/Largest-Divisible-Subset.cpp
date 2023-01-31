class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastidx = 0;
        int maxi = 1;
        
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<i; prev++) {
                if(arr[i]%arr[prev] == 0 && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastidx = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastidx]);
        while(hash[lastidx] != lastidx) {
            lastidx = hash[lastidx];
            temp.push_back(arr[lastidx]);
        }
        return temp;
    }
};
