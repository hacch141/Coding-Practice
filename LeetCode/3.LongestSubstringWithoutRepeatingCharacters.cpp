// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        vector<int> prev(256, -1);
        int n = s.length();
        int ans = 0;
        int i = 0;
        
        for(int j=0; j<s.length(); j++) {
            i = max(i,prev[s[j]]+1);
            int maxend = j-i+1;
            ans = max(ans,maxend);
            prev[s[j]] = j;
        }
        return ans;
    
//     int lengthOfLongestSubstring(string s) { // 2nd Method
        
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         vector<int> letters(256, -1);
//         int maxLen = 0, start = -1;
        
//         for(int i=0; i<s.length(); i++) {
//             if(letters[s[i]]>start)
//                 start = letters[s[i]];
//             letters[s[i]] = i;
//             maxLen = max(maxLen, i-start);
//         }
//         return maxLen;
//     }
};
