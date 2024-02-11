// 3035. Maximum Palindromes After Operations

class Solution {
public:
    
    static bool cmp(const string& a, const string& b) {
        return a.length() < b.length();
    }

    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> f(26, 0);
        int n = words.size(), extra = 0;
        sort(words.begin(), words.end(), cmp);
        for(int i = 0; i < n; i++) {
            for(auto ch : words[i]) {
                f[ch - 'a']++;
            }
        }
        
        int total = 0;
        for(auto i : f) {
            total += i;
            if(i % 2 == 1) total--;
        }
        
        int ptr = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int l = words[i].length();
            total -= l;
            if(l % 2 == 1) {
                total++;
                extra++;
            }
            if(total >= 0) {
                ans = i + 1;
            }
        }
        return ans;
    }
};
