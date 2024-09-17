// 884. Uncommon Words from Two Sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        string token;
        map<string,int> mp;
        while(ss1 >> token) {
            mp[token]++;
        }
        while(ss2 >> token) {
            mp[token]++;
        }

        vector<string> ans;
        for(auto it : mp) {
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};
