// 3223. Minimum Length of String After Operations

class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        for(auto &ch : s) mp[ch]++;

        int ans = 0;
        for(auto &it : mp) {
            ans += it.second % 2 ? 1 : 2;
        }
        
        return ans;
    }
};
