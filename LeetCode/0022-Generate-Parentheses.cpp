// 22. Generate Parentheses

class Solution {
public:

    void solve(int o, int c, int& n, string& str, vector<string>& ans) {
        if(o == n && c == n) {
            ans.push_back(str);
        }

        if(o < n) {
            str.push_back('(');
            solve(o + 1, c, n, str, ans);
            str.pop_back();
        }

        if(c < o) {
            str.push_back(')');
            solve(o, c + 1, n, str, ans);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        solve(0, 0, n, str, ans);
        return ans;
    }
};
