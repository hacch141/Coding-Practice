// Fruits and Baskets

#include <bits/stdc++.h>
int findMaxFruits(string &str, int n) {
    // Write your code here
    int N = str.length();
    unordered_map<char,int> mp;
    int ans = 0;
    int i=0, j=0;

    while(j<n) {
        mp[str[j]]++;
        while(i<j && mp.size() > 2) {
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(mp.find(str[i]));
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(N)
