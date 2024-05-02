// 2023. Number of Pairs of Strings With Concatenation Equal to Target

class Solution {
public:

    int getJ(string& s, string& target, map<string,int>& mp) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(target[i] != s[i]) return 0;
        }
        string sub = target.substr(n);
        return mp[sub] - (sub == s);
    }

    int numOfPairs(vector<string>& nums, string target) {
        map<string,int> mp;
        for(auto s : nums) mp[s]++;

        int ans = 0;
        for(auto s : nums) {
            ans += getJ(s, target, mp);
        }
        return ans;
    }
};
