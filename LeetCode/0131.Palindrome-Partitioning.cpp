// 131. Palindrome Partitioning

class Solution {

private:
    void solve(int idx, string s, vector<string>& path, vector<vector<string>>& ans) {
        if(idx == s.length()) {
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<s.length(); i++) {
            if(isValid(idx,i,s)) {
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }

    bool isValid(int start, int end, string s) {
        while(start<end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
};
