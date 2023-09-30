// 1392. Longest Happy Prefix

class Solution {
public:
    string longestPrefix(string s) {
        int m = s.length();
        vector<int> lps(m);
        lps[0] = 0;
        int j=0, i=1;
        while(i<m) {
            if(s[i] == s[j]) {
                lps[i] = j + 1;
                i++;
                j++;
            }
            else if(j > 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }

        return s.substr(0,lps[m-1]);
    }
};
