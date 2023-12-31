// 1624. Largest Substring Between Two Equal Characters

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int ans = -1, curr = -1;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                curr = i - mp[s[i]] - 1;
                ans = max(ans, curr);
            }
            else {
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
