// 140. Word Break II

class Solution {
public:

    void solve(int ind, int& n, string& s, set<string>& st, string str, vector<string>& cur, vector<string>& ans) {
        if(ind == n) {
            string temp = "";
            for(auto it : cur) temp += (it + " ");
            if(temp.size() > 0 && str.size() == 0) {
                temp.pop_back();
                ans.push_back(temp);
            }
            return;
        }
        str += s[ind];
        solve(ind + 1, n, s, st, str, cur, ans);
        if(st.count(str)) {
            cur.push_back(str);
            solve(ind + 1, n, s, st, "", cur, ans);
            cur.pop_back();
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> ans, cur;
        set<string> st;
        for(auto str : wordDict) st.insert(str);
        string str = "";
        solve(0, n, s, st, str, cur, ans);
        return ans;
    }
};
