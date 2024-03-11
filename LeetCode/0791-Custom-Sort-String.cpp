// 791. Custom Sort String

class Solution {
public:

    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        string ans;
        for(auto ch : order) {
            while(mp[ch]-- > 0) ans.push_back(ch);
        }
        for(auto [ch, freq] : mp) {
            while(freq-- > 0) ans.push_back(ch);
        }
        return ans;
    }
};
