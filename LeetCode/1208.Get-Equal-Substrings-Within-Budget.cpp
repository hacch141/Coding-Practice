// 1208. Get Equal Substrings Within Budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0, r=0, ans=0, n=s.length(), cost=0;

        for(r=0; r<n; r++) {
            cost += abs(s[r]-t[r]);
            while(cost > maxCost) {
                cost -= abs(s[l]-t[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
