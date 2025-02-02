// 3438. Find Valid Pair of Adjacent Digits in String

class Solution {
public:
    string findValidPair(string s) {
        vector<int> f(10, 0);
        for(auto &ch : s) {
            f[ch - '0']++;
        }
        
        string ans;
        int n = s.length();
        for(int i = 0; i < n - 1; i++) {
            if(s[i] != s[i + 1] && f[s[i] - '0'] == (s[i] - '0') && f[s[i + 1] - '0'] == (s[i + 1] - '0')) {
                ans.push_back(s[i]);
                ans.push_back(s[i + 1]);
                break;
            }
        }

        return ans;
    }
};
