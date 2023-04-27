// 319. Bulb Switcher

// Optimal
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};


// Brute Force
class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> v(n,true);
        int ans = 0;

        for(int i=2; i<=n; i++) {
            for(int j=i; j<n+1; j+=i) {
                v[j-1] = !v[j-1];
            }
        }

        for(auto i : v) {
            if(i) ans++;
        }

        return ans;
    }
};
