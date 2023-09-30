#include <bits/stdc++.h>

vector<int> compute_LPS(string& pattern, int m) {
    vector<int> lps(m);
    lps[0] = 0;
    int j=0, i=1;
    while(i<m) {
        if(pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else {
            if(j > 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	vector<int> ans;
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = compute_LPS(pattern, m);

    int i=0, j=0;
    while(i<n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if(j > 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
        if(j == m) {
            ans.push_back(i-m+1);
            j = lps[j-1];
        }
    }

	return ans;
}

// T : O(N+M)
// S : O(M)
