// Generate all binary strings

#include <bits/stdc++.h>

void solve(int i, int& N, int prev, string& s, vector<string>& ans) {
    if(i == N) {
        ans.push_back(s);
        return;
    }

    if(prev == -1 || prev == 0) {
        s[i] = '0';
        solve(i+1,N,0,s,ans);
        s[i] = '1';
        solve(i+1,N,1,s,ans);
    }
    else {
        s[i] = '0';
        solve(i+1,N,0,s,ans);
    }
    return;
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string s(N,'0');
    solve(0,N,-1,s,ans);
    return ans;
}
// T : O(2^N)
// S : O(N)
