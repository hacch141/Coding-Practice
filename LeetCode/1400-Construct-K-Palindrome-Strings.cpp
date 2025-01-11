// 1400. Construct K Palindrome Strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        int singleCnt = 0;
        vector<int> f(26, 0);
        for(auto ch : s) f[ch - 'a']++;
        for(int i = 0; i < 26; i++) singleCnt += f[i] % 2;
        return singleCnt <= k;
    }
};
