// Print all subsequences/Power Set

class Solution{
public:
    void solve(int idx, string& s, string curr, vector<string>& ans) {
        if(idx == s.length()) {
            if(curr!="") ans.push_back(curr);
            return;
        }
        
        solve(idx+1,s,curr+s[idx],ans);
        solve(idx+1,s,curr,ans);
    }

    vector<string> AllPossibleStrings(string s){
        // Code here
        int n = s.length();
        vector<string> ans;
        string curr = "";
        solve(0,s,curr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(n*2^n)
// S : O(n*2^n)
