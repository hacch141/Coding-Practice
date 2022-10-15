// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto i : s) {
            mp[i]++;
        }
        
        int ans = 0;
        int cnt = 0;
        for(auto i : mp) {
            if(i.second%2 == 1) {
                cnt++;
            }
        }
        if(cnt > 0) return s.length()-cnt+1;
        return s.length();
    }
};
