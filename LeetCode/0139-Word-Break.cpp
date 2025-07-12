// 139. Word Break

class Solution {
public:
    bool solve(int ind, int n, string curr, string& s, unordered_set<string>& st, map<pair<int,string>, int>& mp) {
        if(ind == n) {
            return curr == "";
        }

        if(mp.count({ind, curr})) return mp[{ind, curr}];

        bool cut = false;
        curr += s[ind];
        if(st.count(curr)) {
            cut = solve(ind + 1, n, "", s, st, mp);
        }
        bool notcut = solve(ind + 1, n, curr, s, st, mp);
        return mp[{ind, curr}] = cut || notcut;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;
        map<pair<int,string>, int> mp;
        for(auto s : wordDict) st.insert(s);
        return solve(0, n, "", s, st, mp);
    }
};
