// 2566. Maximum Difference by Remapping a Digit

class Solution {
public:
    int minMaxDifference(int num) {
        string mx = to_string(num);
        int n = mx.length();
        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(mx[i] != '9' && ch == ' ') ch = mx[i];
            if(mx[i] == ch) mx[i] = '9';
        }

        string mn = to_string(num);
        ch = mn[0];
        for(int i = 0; i < n; i++) {
            if(mn[i] == ch) mn[i] = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};
