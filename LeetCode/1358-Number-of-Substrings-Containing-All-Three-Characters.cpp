// 1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), left = 0, ans = 0;
        map<char,int> mp;
        for(int right = 0; right < n; right++) {
            mp[s[right]]++;
            while(mp.size() == 3) {
                ans += n - right;
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};

// ===========================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int pos = 0; pos < len; pos++) {
            // Update last position of current character
            lastPos[s[pos] - 'a'] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};
