// Longest Repeating Substring

int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int n = str.length();
    vector<int>mp(26,0);
    int ans = 0;
    int i=0, j=0, maxcnt=0;
  
    while(j<n) {
        mp[str[j]-'A']++;
        maxcnt = max(maxcnt, mp[str[j]-'A']);
        while(i<j && j-i+1-maxcnt > k) {
            mp[str[i]-'A']--;
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(1)
