// Generate all binary strings

#include <bits/stdc++.h>
void solve(int i, int& N, int prev, string s, vector<string>& ans) {
    if(i == N) {
        ans.push_back(s);
        return;
    }

    if(prev == -1 || prev == 0) {
        solve(i+1,N,0,s+"0",ans);
        solve(i+1,N,1,s+"1",ans);
    }
    else {
        solve(i+1,N,0,s+"0",ans);
    }
    return;
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    solve(0,N,-1,"",ans);
    return ans;
}

// T : O(2^N)
// S : O(N * N^2)
