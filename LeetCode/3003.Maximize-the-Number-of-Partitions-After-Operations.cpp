// 3003. Maximize the Number of Partitions After Operations

class Solution {
public:

    unordered_map<long long, int> dp;

    int solve(long long ind, long long vis, string& s, int& k, bool change) {
        if(ind == s.length()) return 1;

        long long key = (((ind << 27) | vis ) << 1) | change;

        if(dp.find(key) != dp.end()) return dp[key];

        int newVis = vis | (1 << s[ind] - 'a');
        int freq = __builtin_popcount(newVis);
        int res;

        if(freq > k) {
            res = 1 + solve(ind + 1, (1 << s[ind] - 'a'), s, k, change);
        }
        else {
            res = solve(ind + 1, newVis, s, k, change);
        }

        if(change) {
            for(int i=0; i<26; i++) {
                int newVis_change = vis | (1 << i);
                int freq_change = __builtin_popcount(newVis_change);
                if(freq_change > k) {
                    res = max(res, 1 + solve(ind + 1, (1 << i), s, k, !change));
                }
                else {
                    res = max(res, solve(ind + 1, newVis_change, s, k, !change));
                }
            }
        }

        return dp[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0, 0, s, k, true);
    }
};
