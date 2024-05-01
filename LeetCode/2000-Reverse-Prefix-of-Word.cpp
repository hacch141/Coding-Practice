// 2000. Reverse Prefix of Word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length(), l = 0, r = 0;
        while(r < n && word[r] != ch) r++;
        while(r < n && l < r) {
            swap(word[l], word[r]);
            l++;
            r--;
        }
        return word;
    }
};
