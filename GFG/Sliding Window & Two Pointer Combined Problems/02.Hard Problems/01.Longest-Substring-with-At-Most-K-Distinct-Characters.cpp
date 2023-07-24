// Longest Substring with At Most K Distinct Characters

#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<char,int> mp;
    int n = str.length();

    int i=0, j=0;
    int ans = 0;

    while(j<n) {
        mp[str[j]]++;
        while(i<j && mp.size() > k) {
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(str[i]);
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}
// T : O(N)
// S : O(N)



int kDistinctChars(int k, string &str)
{
    // Write your code here
    vector<int> mp(26,0);
    int n = str.length();

    int i=0, j=0, cntDist=0;
    int ans = 0;

    while(j<n) {
        if(mp[str[j]-'a'] == 0) cntDist++;
        mp[str[j]-'a']++;
        while(i<j && cntDist > k) {
            mp[str[i]-'a']--;
            if(mp[str[i]-'a'] == 0) cntDist--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}
// T : O(N)
// S : O(1)
