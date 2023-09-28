// 38. Count and Say

class Solution {
public:

    string helper(string str) {
        int n = str.length();
        int cnt = 1;
        string s = "";
        for(int i=0; i<n-1; i++) {
            if(str[i] == str[i+1]) {
                cnt++;
            }
            else {
                s += to_string(cnt) + str[i];
                cnt = 1;
            }
        }
        s += to_string(cnt) + str[n-1];
        return s;
    }

    string countAndSay(int n) {
        string s = "1";
        for(int i=1; i<n; i++) {
            s = helper(s);
        }
        return s;
    }
};
