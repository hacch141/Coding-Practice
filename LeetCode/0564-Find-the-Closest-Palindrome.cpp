// 564. Find the Closest Palindrome

#define ll long long

class Solution {
public:
    ll getPal(ll num, bool odd) {
        ll ans = num;
        if(odd) num /= 10;
        while(num) {
            ans = ans * 10 + (num % 10);
            num /= 10;
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        int len = n.length();
        ll num = stoll(n);
        for(int i = 0; i < len / 2; i++) num /= 10;
        vector<ll> v;
        v.push_back(getPal(num, len & 1));
        v.push_back(getPal(num - 1, len & 1));
        v.push_back(getPal(num + 1, len & 1));
        v.push_back(pow(10, len) + 1);
        v.push_back(pow(10, len - 1) - 1);
        
        ll ans = INT_MAX, diff = INT_MAX, org = stoll(n);
        for(auto i : v) {
            if(i == org) continue;
            ll cur = abs(org - i);
            if(cur < diff) {
                diff = cur;
                ans = i;
            }
            else if(cur == diff) {
                ans = min(ans, i);
            }
        }
        return to_string(ans);
    }
};


// =================================================================


class Solution {
public:
    bool isPal(string& s) {
        int n = s.length(), l = 0, r = n - 1;
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    string genPal(string& s, bool odd) {
        int n = s.length();
        string a = s, b;
        if(odd) b = s.substr(0, n - 1);
        else b = s;
        reverse(b.begin(), b.end());
        return a + b;
    }

    void add1(string& s) {
        long long num = stoll(s);
        num++;
        s =  to_string(num);
    }

    void sub1(string& s) {
        long long num = stoll(s);
        num--;
        s = to_string(num);
    }

    bool isAll9(string& s) {
        for(auto ch : s) {
            if(ch != '9') return false;
        }
        return true;
    }

    bool isAll10(string& s) {
        if(s[0] != '1') return false;
        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(s[i] != '0') return false;
        }
        return true;
    }

    bool isAll101(string& s) {
        int n = s.length();
        if(s[0] != '1' || s[n - 1] != '1') return false;
        for(int i = 1; i < n - 1; i++) {
            if(s[i] != '0') return false;
        }
        return true;
    }

    string getMN(string& pal1, string& pal2, string& s) {
        long long a = stoll(pal1), b = stoll(pal2), num = stoll(s);
        long long ans;
        if(abs(num - a) < abs(num - b)) {
            ans = a;
        }
        else if(abs(num - a) > abs(num - b)) {
            ans = b;
        }
        else {
            ans = min(a, b);
        }
        return to_string(ans);
    }

    string nearestPalindromic(string s) {

        if(s == "1" || s == "9") {
            sub1(s);
            return s;
        }
        else if(isAll9(s)) {
            add1(s);
            add1(s);
            return s;
        }
        else if(isAll10(s)) {
            sub1(s);
            return s;
        }
        else if(isAll101(s)) {
            sub1(s);
            sub1(s);
            return s;
        }

        int n = s.length();
        string pal1, pal2;
        if(isPal(s)) {
            string tmp = s.substr(0, n / 2 + n % 2);
            add1(tmp);
            pal1 = genPal(tmp, n % 2);
            sub1(tmp); sub1(tmp);
            pal2 = genPal(tmp, n % 2);
        }
        else {
            string tmp = s.substr(0, n / 2 + n % 2);
            pal1 = genPal(tmp, n % 2);
            if(pal1 < s) {
                add1(tmp);
                pal2 = genPal(tmp, n % 2);
            }
            else {
                sub1(tmp);
                pal2 = genPal(tmp, n % 2);
            }
        }
        return getMN(pal1, pal2, s);
    }
};
