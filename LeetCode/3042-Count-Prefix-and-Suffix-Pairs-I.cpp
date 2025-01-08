// 3042. Count Prefix and Suffix Pairs I

class Solution {
public:
    bool isPrefixAndSuffix(int i, int j, vector<string>& words) {
        int ni = words[i].length(), nj = words[j].length();
        if(ni > nj) return false;
        for(int k = 0; k < ni; k++) {
            if(words[i][k] != words[j][k] || words[i][ni - 1 - k] != words[j][nj - 1 - k]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                ans += isPrefixAndSuffix(i, j, words);
            }
        }
        return ans;
    }
};
