// 2929. Distribute Candies Among Children II

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(n, limit); i++) {
            int c = n - i;
            if(c <= 2 * limit) {
                int mn = max(c - limit, 0), mx = min(c, limit);
                ans += mx - mn + 1;
            }
        }
        return ans;
    }
};
