// 87. Scramble String

class Solution {
public:

    bool solve(string s1, string s2, unordered_map<string,bool>& mp) {

        if(mp.find(s1+s2) != mp.end()) return mp[s1+s2];

        if(s1.length() != s2.length()) return false;
        if(s1.compare(s2)==0) return true;

        if(s1.length()<=1 || s2.length()<=1) return false;
        int n = s1.length();

        bool swap, noswap;
        bool flag = false;

        for(int i=1; i<n; i++) {

            swap = solve(s1.substr(0,i),s2.substr(n-i,i),mp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),mp);
            noswap = solve(s1.substr(0,i),s2.substr(0,i),mp) && solve(s1.substr(i,n-i),s2.substr(i,n-i),mp);
            flag = swap||noswap;
            if(flag) {
                mp[s1+s2] = true;
                return true;
            }
        }
        mp[s1+s2] = false;
        return false;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> mp;
        return solve(s1,s2,mp);
    }
};
