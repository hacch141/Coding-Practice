// 1347. Minimum Number of Steps to Make Two Strings Anagram

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(auto i : s) freq[i - 'a']++;
        for(auto i : t) freq[i - 'a']--;

        int ans = 0;
        for(auto i : freq) if(i > 0) ans += i;
        return ans;
    }
};
