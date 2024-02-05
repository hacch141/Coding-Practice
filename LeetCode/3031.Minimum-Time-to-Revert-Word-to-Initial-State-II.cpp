// 3031. Minimum Time to Revert Word to Initial State II

class Solution {
public:

    vector<int> kmp(string& s) {
        int n = s.length();
        vector<int> lps(n, 0);

        for(int i = 1; i < n; i++) {
            int prev_ind = lps[i - 1];
            while(prev_ind > 0 && s[i] != s[prev_ind]) {
                prev_ind = lps[prev_ind - 1];
            }
            lps[i] = prev_ind + (s[i] == s[prev_ind]);
        }

        return lps;
    }

    int minimumTimeToInitialState(string word, int k) {
        vector<int> lps = kmp(word);
        int n = word.length();
        int mx = lps[n - 1];
        while(mx > 0 && (n - mx) % k != 0) {
            mx = lps[mx - 1];
        }
        return (n - mx) % k == 0 ? (n - mx) / k : (n + k - 1) / k;
    }
};
