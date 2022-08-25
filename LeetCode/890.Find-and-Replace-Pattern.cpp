// 890. Find and Replace Pattern

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        int n = pattern.length();
        for(int i=0; i<words.size(); i++) {
            string s = words[i];
            int k;
            for(k=0; k<n; k++) {
                if(pattern.find(pattern[k]) != s.find(s[k])) {
                    break;
                }
            }
            if(k == n) {
                ans.push_back(s);   
            }
        }
        return ans;
    }
};
