// 1432. Max Difference You Can Get From Changing an Integer

class Solution {
public:
    int maxDiff(int num) {
        string mx = to_string(num);
        int n = mx.length();
        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(mx[i] != '9' && ch == ' ') ch = mx[i];
            if(mx[i] == ch) mx[i] = '9';
        }

        string mn = to_string(num);
        ch = ' ';
        if(mn[0] != '1') {
            ch = mn[0];
            for(int i = 0; i < n; i++) {
                if(mn[i] == ch) mn[i] = '1';
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                if(mn[i] != '1' && mn[i] != '0' && ch == ' ') ch = mn[i];
                if(mn[i] == ch) mn[i] = '0';
            }
        }

        return stoi(mx) - stoi(mn);
    }
};
