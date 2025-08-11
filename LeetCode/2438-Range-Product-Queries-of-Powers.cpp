// 2438. Range Product Queries of Powers

class Solution {
public:
    int MOD = 1e9 + 7;

    long long num_pow(long long base, long long pow) {
        long long res = 1;
        while(pow > 0) {
            if(pow & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            pow >>= 1;
        }
        return res;
    }


    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers, ans;
        int bit = 0;
        while(n) {
            if(n & 1) {
                powers.push_back(1 << bit);
            }
            bit++;
            n >>= 1;
        }

        vector<int> pref(powers);
        for(int i = 1; i < pref.size(); i++) {
            pref[i] = (1LL * pref[i] * pref[i - 1]) % MOD;
        }

        for(auto q : queries) {
            long long curr = pref[q[1]];
            if(q[0] > 0) curr = (curr * num_pow(pref[q[0] - 1], MOD - 2)) % MOD;
            ans.push_back(curr);
        }

        return ans;
    }
};
