// 438. Find All Anagrams in a String

class Solution {
public:
    
    bool compare(int CT[], int CP[]) {
        for(int i=0; i<26; i++) {
            if(CT[i] != CP[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int CP[26] = {0};
        int CT[26] = {0};
        if(p.length() > s.length()) {
            return {};
        }
        for(int i=0; i<p.length(); i++) {
            CT[s[i]-'a']++;
            CP[p[i]-'a']++;
        }
        for(int i=p.length(); i<s.length(); i++) {
            if(compare(CT,CP)) {
                ans.push_back(i-p.length());
            }
            CT[s[i]-'a']++;
            CT[s[i-p.length()]-'a']--;
        }
        if(compare(CT,CP)) {
            ans.push_back(s.length()-p.length());
        }
        return ans;
    }
};
