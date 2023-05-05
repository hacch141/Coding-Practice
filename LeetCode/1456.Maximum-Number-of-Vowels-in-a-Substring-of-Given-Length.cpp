// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        int count = 0;
        for (int i=0; i<s.length(); i++) {
            if (i >= k && vowels.count(s[i-k])) {
                count--;
            }
            if (vowels.count(s[i])) {
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
