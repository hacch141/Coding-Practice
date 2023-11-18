// 1839. Longest Substring Of All Vowels in Order

class Solution {
public:

    int longestBeautifulSubstring(string word) {
        int l = 0, r = 0, ans = 0, n = word.length(), len = 1;
        unordered_map<char,int> mp;

        mp[word[0]]++;
        for (r=1; r<n; r++) {
            if(word[r] >= word[r-1]) {
                mp[word[r]]++;
                len++;
            }
            else {
                if(mp['a']!=0 && mp['e']!=0 && mp['i']!=0 && mp['o']!=0 && mp['u']!=0) {
                    ans = max(ans, len);
                }
                mp.clear();
                mp[word[r]]++;
                len = 1;
            }
        }

        if(mp['a']!=0 && mp['e']!=0 && mp['i']!=0 && mp['o']!=0 && mp['u']!=0) {
            ans = max(ans, len);
        }

        return ans;
    }
};
