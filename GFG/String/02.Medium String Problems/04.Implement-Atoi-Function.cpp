// Implement Atoi Function

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
