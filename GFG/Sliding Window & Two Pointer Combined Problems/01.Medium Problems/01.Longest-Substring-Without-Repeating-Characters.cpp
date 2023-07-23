// Longest Substring Without Repeating Characters

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.length();
    int ans = INT_MIN;
    unordered_map<char,int> mp;

    int i = 0, j = 0;
    while(j<n) {
        while(i<j && mp.find(input[j]) != mp.end()) {
            mp[input[i]]--;
            if(mp[input[i]] == 0) mp.erase(mp.find(input[i]));
            i++;
        }
        ans = max(ans, j-i+1);
        mp[input[j]]++;
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(N)
