// 1371. Find the Longest Substring Containing Vowels in Even Counts

class Solution {
public:

    int getInd(char ch) {
        if(ch == 'a') return 0;
        if(ch == 'e') return 1;
        if(ch == 'i') return 2;
        if(ch == 'o') return 3;
        if(ch == 'u') return 4;
        return -1;
    }

    int findTheLongestSubstring(string s) {
        int n = s.length(), mx = 0;
        map<string,int> mp;
        string f(5, '0');
        mp[f] = -1;
        for(int i = 0; i < n; i++) {
            int ind = getInd(s[i]);
            if(ind != -1) f[ind] = (f[ind] == '0') ? '1' : '0';
            if(mp.find(f) != mp.end()) mx = max(mx, i - mp[f]);
            else mp[f] = i;
        }
        return mx;
    }
};
