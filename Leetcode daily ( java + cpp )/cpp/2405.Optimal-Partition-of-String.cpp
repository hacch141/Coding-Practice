// 2405. Optimal Partition of String

class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int i=0;
        unordered_map<int,int> mp;
        int ans = 0;
        while(i < n) {
            if(mp.find(s[i]) != mp.end()) {
                ans++;
                mp.clear();
                mp[s[i]]++;
            }
        }
        return ans;
    }
};
