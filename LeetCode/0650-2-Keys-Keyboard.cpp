// 650. 2 Keys Keyboard

class Solution {
public:
    int minSteps(int n) {
        map<int,int> mp;
        for(int i = 2; i <= n; i++) {
            while(n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
        int ans = 0;
        for(auto it : mp) ans += it.first * it.second;
        return ans;
    }
};
