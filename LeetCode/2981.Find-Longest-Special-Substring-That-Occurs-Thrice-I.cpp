// 2981. Find Longest Special Substring That Occurs Thrice I


class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(), ans = 0;
        vector<vector<int>> f(26, vector<int>(51, 0));
        for(int i = 0; i < n; i++) {
            int len = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == s[i]) len++;
                else break;
                f[s[j] - 'a'][len]++;
                if(f[s[j] - 'a'][len] >=3) ans = max(ans, len);
            }
        }
        return ans != 0? ans : -1;
    }
};


// ====================================================

class Solution {
public:

    bool onlyOne(vector<int>& freq) {
        int c = 0;
        for(auto i : freq) if(i != 0) c++;
        return c == 1;
    }

    bool isValid(int l, string& s) {
        int n = s.length();
        vector<int> c(26,0), freq(26, 0);

        for(int i = 0; i < l; i++) {
            freq[s[i] - 'a']++;
        }

        if(onlyOne(freq)) c[s[0] - 'a']++;
        
        for(int i = l; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[s[i - l] - 'a']--;
            if(onlyOne(freq)) c[s[i] - 'a']++;
        }

        for(auto i : c) if(i >= 3) return true;

        return false;
    }

    int maximumLength(string s) {
        int n = s.length(), l = 1, h = n, ans = -1;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(isValid(m, s)) {
                ans = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return ans;
    }
};
