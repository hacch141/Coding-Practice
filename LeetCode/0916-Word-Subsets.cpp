// 916. Word Subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f2(26, 0);
        for(auto &s2 : words2) {
            vector<int> f(26, 0);
            for(auto &ch : s2) {
                f[ch - 'a']++;
                f2[ch - 'a'] = max(f2[ch - 'a'], f[ch - 'a']);
            }
        }

        vector<string> ans;
        for(auto &s1 : words1) {
            vector<int> f1(26, 0);
            bool f = true;
            for(auto &ch : s1) f1[ch - 'a']++;
            for(int i = 0; i < 26; i++) if(f2[i] > f1[i]) f = false;
            if(f) ans.push_back(s1);
        }
        return ans;
    }
};
