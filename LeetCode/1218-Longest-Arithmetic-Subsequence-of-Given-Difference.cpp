// 1218. Longest Arithmetic Subsequence of Given Difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - difference]);
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};
