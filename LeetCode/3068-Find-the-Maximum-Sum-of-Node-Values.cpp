// 3068. Find the Maximum Sum of Node Values

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, cnt = 0, mn = LLONG_MAX;
        for(auto i : nums) {
            if((i ^ k) > i) {
                cnt++;
                ans += (i ^ k);
                mn = min(mn, (long long)(i ^ k) - i);
            }
            else {
                ans += i;
                mn = min(mn, (long long)i - (i ^ k));
            }
        }
        return cnt % 2 == 0 ? ans : ans - mn;
    }
};
