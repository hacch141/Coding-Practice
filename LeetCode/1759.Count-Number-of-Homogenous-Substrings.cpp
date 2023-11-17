// 1759. Count Number of Homogenous Substrings

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        int ans = 0;
        int mod = 1e9 + 7;

        int len = 1;
        for(int i=1; i<n; i++) {
            if(s[i] == s[i-1]) {
                len++;
            }
            else {
                int curr = ((1LL*len*(len+1))/2) % mod;
                ans = (ans + curr) % mod;
                len = 1;
            }
        }
        int curr = ((1LL*len*(len+1))/2) % mod;
        ans = (ans + curr) % mod;

        return ans;
    }
};
