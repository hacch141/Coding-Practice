// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> letters(256, -1);
        int maxLen = 0, start = -1;
        
        for(int i=0; i<s.length(); i++) {
            if(letters[s[i]]>start)
                start = letters[s[i]];
            letters[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
