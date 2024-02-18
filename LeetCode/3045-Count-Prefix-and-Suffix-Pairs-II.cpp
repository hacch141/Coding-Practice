// 3045. Count Prefix and Suffix Pairs II

class StringHash {
public:
    long long base1 = 31, base2 = 61, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    vector<long long> hs1, hs2;

    StringHash(string s) {
        int n = s.length();
        hs1.resize(n + 1, 0);
        hs2.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            int c = s[i - 1] + 1;
            hs1[i] = ((hs1[i - 1] * base1) % mod1 + c) % mod1;
            hs2[i] = ((hs2[i - 1] * base2) % mod2 + c) % mod2;
        }
    }

    long long powxy(long long num, long long pow, long long mod) {
        if(pow == 0) return 1;
        long long half = powxy(num, pow / 2, mod);
        return (((half * half) % mod) * (pow % 2 == 1 ? num : 1)) % mod;
    }

    pair<long long, long long> substrHash(int l, int r) {
        long long rem1 = (powxy(base1, r - l + 1, mod1) * hs1[l]) % mod1;
        long long rem2 = (powxy(base2, r - l + 1, mod2) * hs2[l]) % mod2;
        return {(hs1[r + 1] - rem1 + mod1) % mod1 , (hs2[r + 1] - rem2 + mod2) % mod2};
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long n = words.size(), ans = 0;
        map<pair<long long, long long>,long long> mp;
        for(int i = n - 1; i >= 0; i--) {
            auto it = StringHash(words[i]);
            int m = words[i].length();
            auto h = it.substrHash(0, m - 1);
            if(mp.find(h) != mp.end()) ans += mp[h];
            for(int j = 0; j < m; j++) {
                auto h1 = it.substrHash(0, j), h2 = it.substrHash(m - 1 - j, m - 1);
                if(h1 == h2) {
                    mp[h1]++;
                }
            }
        }
        return ans;
    }
};
