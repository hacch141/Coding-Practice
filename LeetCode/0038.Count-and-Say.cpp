// 38. Count and Say

class Solution {
public:

    string rec(int n) {
        if(n == 1) return "1";
        string s = rec(n - 1), ans = "";
        char lst_ch = s[0];
        int cnt = 0;

        for(int i = 0; i < s.length(); i++) {
            if(lst_ch == s[i]) {
                cnt++;
            }
            else {
                ans += to_string(cnt);
                ans += lst_ch;
                lst_ch = s[i];
                cnt = 1;
            }
        }

        ans += to_string(cnt);
        ans += lst_ch;

        return ans;
    }

    string countAndSay(int n) {
        return rec(n);
    }
};
