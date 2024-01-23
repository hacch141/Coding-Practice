// 2982. Find Longest Special Substring That Occurs Thrice II


class Solution {
public:

    int maximumLength(string s) {
        int n = s.length(), ans = -1, c = 1;
        vector<vector<int>> freq(26, vector<int>(3, -1));

        char prev = s[0];
        freq[prev - 'a'][0] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == prev) {
                c++;
            }
            else {
                c = 1;
                prev = s[i];
            }
            
            int ind = prev - 'a';
            if(c > freq[ind][0]) {
                freq[ind][2] = freq[ind][1];
                freq[ind][1] = freq[ind][0];
                freq[ind][0] = c;
            }
            else if(c > freq[ind][1]) {
                freq[ind][2] = freq[ind][1];
                freq[ind][1] = c;
            }
            else if(c > freq[ind][2]) {
                freq[ind][2] = c;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i][2] > ans) ans = freq[i][2];
        }

        return ans;
    }
};

// ================================================================



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
