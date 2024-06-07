// 1002. Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> f(26, INT_MAX);
        for(auto s : words) {
            vector<int> cur(26, 0);
            for(auto ch : s) cur[ch - 'a']++;
            for(int i = 0; i < 26; i++) f[i] = min(f[i], cur[i]);
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < f[i]; j++) {
                ans.push_back(string(1,i + 'a'));
            }
        }
        return ans;
    }
};
