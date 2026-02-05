// Implement Atoi Function

class Solution {
    int MN = Integer.MIN_VALUE;
    int MX = Integer.MAX_VALUE;

    public boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    public int myAtoi(String s) {
        int n = s.length();

        int i = 0;
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        if (i == n) return 0;

        int sign = 1;
        if (s.charAt(i) == '+') {
            i++;
        }
        else if (s.charAt(i) == '-') {
            sign = -1;
            i++;
        }

        long ans = 0;
        while (i < n && isDigit(s.charAt(i))) {
            ans = (ans * 10) + (s.charAt(i) - '0');
            if (ans * sign <= MN) {
                return MN;
            }
            else if(ans * sign >= MX) {
                return MX;
            }
            i++;
        }

        return (int)ans * sign;
    }
}

// ==============================================================

int getNum(string &s, int &ind) {
    int n = s.length();
    int sign = 1;
    if(s[ind] == '-') {
        sign = -1;
        ind++;
    }
    else if(s[ind] == '+') {
        ind++;
    }

    double num = 0;
    while(ind<n && (s[ind]>='0' && s[ind]<='9')) {
        num = (num*10) + (s[ind]-'0');
        ind++;
    }

    if(sign==1 && num > INT_MAX) return INT_MAX;
    if(sign==-1 && -num < INT_MIN) return INT_MIN;

    return sign==1 ? num : -num;
}

int createAtoi(string s) {
    // Write your code here.
    int n = s.length();
    int ptr = 0;
    while(ptr<n) {
        if(s[ptr]=='-' || s[ptr]=='+' || (s[ptr]>='0' && s[ptr]<='9')) {
            return getNum(s,ptr);
        }
        ptr++;
    }
    return 0;
}
// T : O(N)
// S : O(1)
