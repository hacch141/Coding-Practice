// 592. Fraction Addition and Subtraction

class Solution {
public:

    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int getNum(string& s, int& ptr) {
        int a = 0;
        if(s[ptr] == '/') ptr++;
        while(s[ptr] >= '0' && s[ptr] <= '9') {
            a = (a * 10) + (s[ptr] - '0');
            ptr++;
        }
        return a;
    }

    string fractionAddition(string s) {
        int n = s.length(), ptr = 0;
        map<int,int> mp;
        while(ptr < n) {
            bool Aneg = false;
            if(s[ptr] == '-') {
                Aneg = true;
                ptr++;
            }
            else if(s[ptr] == '+') {
                ptr++;
            }

            int a = getNum(s, ptr);
            int b = getNum(s, ptr);

            mp[b] += Aneg ? -a : a;
        }

        int num = 0, den = -1;
        for(auto it : mp) {
            if(den == -1) {
                den = it.first;
            }
            else {
                den = lcm(den, it.first);
            }
        }

        for(auto it : mp) {
            int mul = den / it.first;
            num += it.second * mul;
        }

        int gc = gcd(abs(num), den);
        num /= gc;
        den /= gc;

        string ans = to_string(num) + '/' + to_string(den);
        return ans;
    }
};
