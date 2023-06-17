// 1187. Make Array Strictly Increasing

class Solution {
public:

    int solve(int ind, int prev, vector<int>& arr1, vector<int>& arr2, map<pair<int,int>,int>& dp) {
        if(ind==arr1.size()) return 0;
        if(dp.find({ind,prev}) != dp.end()) return dp[{ind,prev}];
      
        int take=1e9, nottake=1e9;
        int upper = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        if(arr1[ind]>prev) nottake = 0 + solve(ind+1,arr1[ind],arr1,arr2,dp);
        if(upper<arr2.size()) take = 1 + solve(ind+1,arr2[upper],arr1,arr2,dp);
      
        return dp[{ind,prev}] = min(take,nottake);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int> dp;
        sort(arr2.begin(),arr2.end());
        int ans = solve(0,INT_MIN,arr1,arr2,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
