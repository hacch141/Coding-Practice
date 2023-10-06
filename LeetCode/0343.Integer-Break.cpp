// 343. Integer Break

class Solution {
public:

    int solve(int ind, int sum, int n, vector<int>& nums, unordered_map<string,int>& mp) {
        if(ind == n-1 || sum == n) {
            return 1;
        }

        string s = to_string(ind) + "#" + to_string(sum);
        if(mp.find(s) != mp.end()) {
            return mp[s];
        }

        int take = INT_MIN;
        if(sum+nums[ind] <= n) {
            take = nums[ind] * solve(ind , sum+nums[ind] , n , nums , mp);
        }

        int nottake = solve(ind+1 , sum , n , nums , mp);

        return mp[s] = max(take , nottake);
    }

    int integerBreak(int n) {
        vector<int> nums(n-1,0);
        for(int i=0; i<n-1; i++) {
            nums[i] = i+1;
        }

        unordered_map<string,int> mp;
        return solve(0,0,n,nums,mp);
    }
};
