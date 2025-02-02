// 3442. Maximum Difference Between Even and Odd Frequency I

class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26, 0);
        for(auto &ch : s) {
            f[ch - 'a']++;
        }

        int ans = INT_MIN;
        int even_mn = INT_MAX, odd_mx = 0;
        for(auto &i : f) {
            if(i == 0) continue;
            if(i & 1) odd_mx = max(odd_mx, i);
            else even_mn = min(even_mn, i);
        }
        ans = max(ans, odd_mx - even_mn);

        return ans;
    }
};
