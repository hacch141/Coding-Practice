// Count Substrings With K Ones

#include <bits/stdc++.h> 
int countSubstr(string &s, int k) {
    // Write your code here.
    int n = s.length();

    vector<int> prefix(n+1,0);
    prefix[0] = 1;

    int cnt1 = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        cnt1 += s[i]-'0';
        if(cnt1 >= k) {
            ans += prefix[cnt1-k];
        }
        prefix[cnt1]++;
    }
    return ans;
}
// T : O(N)
// S : O(N)
