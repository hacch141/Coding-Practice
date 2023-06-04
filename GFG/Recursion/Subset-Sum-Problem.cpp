// Subset Sum Problem

class Solution{   
public:

    bool solve(int idx, int& n, vector<int>& arr, int& sum, int curr, vector<vector<int>>& dp) {
        if(idx==n) {
            return curr==sum ? true : false;
        }
        
        if(dp[idx][curr] != -1) return dp[idx][curr];
        
        bool take = solve(idx+1,n,arr,sum,curr+arr[idx],dp);
        bool nottake = solve(idx+1,n,arr,sum,curr,dp);
        
        return dp[idx][curr] = take||nottake;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        int curr = 0;
        int total = 0;
        for(auto i : arr) total += i;
        vector<vector<int>> dp(n, vector<int>(total+1,-1));
        return solve(0,n,arr,sum,curr,dp);
    }
};
