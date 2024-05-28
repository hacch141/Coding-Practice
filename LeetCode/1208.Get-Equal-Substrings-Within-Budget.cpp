// 1208. Get Equal Substrings Within Budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), l = 0, r = 0, cost = 0, ans = 0;
        while(r < n) {
            cost += abs(s[r] - t[r]);
            while(l <= r && cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            if(cost <= maxCost) ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
