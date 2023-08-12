// Generate Paranthesis

#include <bits/stdc++.h>

void solve(int i, int j, int &N, string &s, vector<string> &ans) {
    if(i == N && j == N) {
        ans.push_back(s);
        return;
    }

    if(i<N) {
        s[i+j] = '(';
        solve(i+1,j,N,s,ans);
    }
    if(j<i && j<N) {
        s[i+j] = ')';
        solve(i,j+1,N,s,ans);
    }
    return;
}

vector<string> validParenthesis(int N){
    // Write your code here.
    vector<string> ans;
    string s(2*N,' ');
    solve(0,0,N,s,ans);
    return ans;
}

// T : O(2^(2*N)
// S : O(2*N + ans + STACK)
