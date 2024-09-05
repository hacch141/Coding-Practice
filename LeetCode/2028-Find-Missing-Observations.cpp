// 2028. Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = 0;
        for(auto i : rolls) sum += i;

        int rem = (n + m) * mean - sum;
        if(rem < n || rem > n * 6) return {};

        vector<int> ans(n);
        int add = rem / n, md = rem % n;
        for(int i = 0; i < n; i++) {
            ans[i] += add;
            if(i < md) ans[i]++;
        }
        return ans;
    }
};
