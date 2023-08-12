// Print all subsequences/Power Set

void solve(int i, string& curr, string& s, vector<string>& ans) {
    if(i == s.size()) {
        ans.push_back(curr);
        return;
    }
    solve(i+1,curr,s,ans);
    curr += s[i];
    solve(i+1,curr,s,ans);
    curr.pop_back();
    return;
}

vector<string> generateSubsequences(string s) {
    // Write your code here.
    vector<string> ans;
    string curr;
    solve(0,curr,s,ans);
    return ans;
}

// T : O(2^N)
// S : O(N)


// BitMasking
vector<string> generateSubsequences(string s)
{
    // Write your code here.
    int n = s.size();
    vector<string> ans;
    
    int total = (1<<n);
    for(int i=0; i<total; i++) {
        string curr = "";
        for(int j=n-1; j>=0; j--) {
            if((i>>j) & 1) {
                curr += s[n-1-j];
            }
        }
        ans.push_back(curr);
    }
    return ans;
}

// T : O(2^N * N)
// S : O(ans)
