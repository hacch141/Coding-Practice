// 1239. Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:

    int isValid(string& str, int& mask) {
        int newMask = mask;
        for(auto i : str) {
            if(newMask & (1 << (i - 'a'))) return -1;
            newMask |= (1 << (i - 'a'));
        }
        return newMask;
    }

    int solve(int ind, int& n, vector<string>& arr, int& mask, vector<unordered_map<int,int>>& dp) {
        if(ind == n) return __builtin_popcount(mask);

        if(dp[ind].find(mask) != dp[ind].end()) return dp[ind][mask];

        int nottake, take = 0;
        int newMask = isValid(arr[ind], mask);
        
        if(newMask != -1) {
            take = solve(ind + 1, n, arr, newMask, dp);
        }

        nottake = solve(ind + 1, n, arr, mask, dp);
        return dp[ind][mask] = max(take, nottake);
    }

    int maxLength(vector<string>& arr) {
        int mask = 0, n = arr.size();
        vector<unordered_map<int,int>> dp(n+1);
        return solve(0, n, arr, mask, dp);
    }
};
