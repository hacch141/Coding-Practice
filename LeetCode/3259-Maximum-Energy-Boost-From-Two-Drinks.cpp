// 3259. Maximum Energy Boost From Two Drinks

#define ll long long

class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<ll> prefA(n), prefB(n);
        prefA[0] = a[0];
        prefA[1] = a[0] + a[1];
        prefB[0] = b[0];
        prefB[1] = b[0] + b[1];
        
        for(int i = 2; i < n; i++) {
            prefA[i] += a[i] + max(prefA[i - 1], prefB[i - 2]);
            prefB[i] += b[i] + max(prefB[i  -1], prefA[i - 2]);
        }
        return max(prefA[n - 1], prefB[n - 1]);
    }
};
