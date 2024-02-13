// 2108. Find First Palindromic String in the Array

class Solution {
public:

    bool isPalin(string& s) {
        int l = 0, h = s.length() - 1;
        while(l <= h) {
            if(s[l] != s[h]) return false;
            l++, h--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            if(isPalin(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};
