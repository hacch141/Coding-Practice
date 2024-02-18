// 3039. Apply Operations to Make String Empty

class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(auto i : s) freq[i - 'a']++;
        int mx = INT_MIN;
        for(auto i : freq) mx = max(mx, i);
        
        string ans = "";
        for(int i = n - 1; i >= 0; i--) {
            if(freq[s[i] - 'a'] == mx) {
                ans += s[i];
                freq[s[i] - 'a'] = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
