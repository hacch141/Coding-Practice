// 1657. Determine if Two Strings Are Close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[26] = {0}, freq2[26] = {0};
        bool check[26] = {false};
        for(auto i : word1) {
            freq1[i - 'a']++;
            check[i - 'a'] = true;
        }
        
        for(auto i : word2) {
            freq2[i - 'a']++;
            if(!check[i-'a']) return false;
        }

        unordered_map<int,int> mp;
        for(int i=0; i<26; i++) {
            mp[freq1[i]]++;
            mp[freq2[i]]--;
        }

        for(auto i : mp) if(i.second != 0) return false;

        return true;
    }
};
