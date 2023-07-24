// Count Substring With abc

int countSubstring(string s){
    // Write your code here.
    int n = s.length();
    vector<int> freq(26,0);
    
    int i=0, j=0;
    int ans = 0;
    while(j<n) {
        freq[s[j]-'a']++;
        while(i<j && freq[0] && freq[1] && freq[2]) {
            freq[s[i]-'a']--;
            i++;
        }
        ans += i;
        j++;
    }
    return ans;
}
// T : O(N)
// S : O(1)

int countSubstring(string s)
{ 
    int ans = 0;
    int n = s.size();
  
    int aIdx = -1, bIdx = -1, cIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            aIdx = i;
        }
        else if (s[i] == 'b')
        {
            bIdx = i;
        }
        else if (s[i] == 'c')
        {
            cIdx = i;
        }

        int minIdx = min(aIdx, min(bIdx, cIdx));

        // Adding count of all valid substrings.
        ans = ans + (minIdx + 1);
    }
    return ans;
}
// T : O(N)
// S : O(1)
