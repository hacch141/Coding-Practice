#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll mod = (ll)1e9 + 7;

ll pw(ll num, ll pow) {
    ll ans = 1;
    while(pow) {
        if(pow&1) {
            ans = (ans*num) % mod;
        }
        num = (num*num) % mod;
        pow >>= 1;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    ll n = s.length(), l = 0, r = n-1;
    while(l <= r) {
        if(s[l] == s[r]) {
            l++, r--;
        }
        else break;
    }
    if(l >= r) {
        cout << s << endl;
        return;
    }

    ll h1 = 0, h2 = 0, h3 = 0, h4 = 0, len1 = 0, len2 = 0;
    for(ll i=l; i<=r; i++) {
        h1 = (((h1*137) % mod) + (s[i] - 'a' + 1)) % mod;
        h2 = (h2 + ((s[i] - 'a' + 1)*pw(137,i-l)) % mod) % mod;

        h3 = (((h3*61) % mod) + (s[i] - 'a' + 1)) % mod;
        h4 = (h4 + ((s[i] - 'a' + 1)*pw(61,i-l)) % mod) % mod;

        if(h1 == h2 && h3 == h4) {
            if(i-l+1 > len1) len1 = i-l+1;
        }
    }

    h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    for(ll i=r; i>=l; i--) {
        h1 = (((h1*137) % mod) + (s[i] - 'a' + 1)) % mod;
        h2 = (h2 + ((s[i] - 'a' + 1)*pw(137,r-i)) % mod) % mod;

        h3 = (((h3*61) % mod) + (s[i] - 'a' + 1)) % mod;
        h4 = (h4 + ((s[i] - 'a' + 1)*pw(61,r-i)) % mod) % mod;

        if(h1 == h2 && h3 == h4) {
            if(r-i+1 > len2) len2 = r-i+1;
        }
    }

    if(len1 >= len2) cout << s.substr(0,l+len1) + s.substr(r+1) << endl;
    else cout << s.substr(0,l) + s.substr(r-len2+1) << endl;
}
 
int main() {
 
    speed();
 
    ll t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// typedef vector<long long> vll;

// #define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

// ll mod = (ll)1e9 + 7;
// vll deg1(1000002), deg2(1000002), p1(1000002, 0), s1(1000002, 0), p2(1000002, 0), s2(1000002, 0);

// ll pref1(ll l, ll r) {
//     return ((p1[r] - (p1[l - 1] * deg1[r - l + 1]) % mod) + mod) % mod;
// }

// ll pref2(ll l, ll r) {
//     return ((p2[r] - (p2[l - 1] * deg2[r - l + 1]) % mod) + mod) % mod;
// }

// ll suff1(ll l, ll r) {
//     return ((s1[l] - (s1[r + 1] * deg1[r - l + 1]) % mod) + mod) % mod;
// }

// ll suff2(ll l, ll r) {
//     return ((s2[l] - (s2[r + 1] * deg2[r - l + 1]) % mod) + mod) % mod;
// }

// string solve(string &str) {
//     ll n = str.length();

//     for (ll i = 1; i <= n; i++) {
//         p1[i] = (p1[i - 1] * 31 + (str[i - 1] - 'a' + 1)) % mod;
//         p2[i] = (p2[i - 1] * 61 + (str[i - 1] - 'a' + 1)) % mod;
//     }
//     s1[n + 1] = 0, s2[n + 1] = 0;
//     for (ll i = n; i >= 1; i--) {
//         s1[i] = (s1[i + 1] * 31 + (str[i - 1] - 'a' + 1)) % mod;
//         s2[i] = (s2[i + 1] * 61 + (str[i - 1] - 'a' + 1)) % mod;
//     }

//     ll ptr = 0;
//     for (ll i = 1; i <= (n + 1) / 2; i++)
//         if (p1[i] == s1[n + 1 - i] && p2[i] == s2[n + 1 - i])
//             ptr = i;

//     if (ptr == (n + 1) / 2)
//         return str;

//     ll ls = 0, rs = 0;
//     for (ll i = ptr + 1; i <= n - ptr; i++)
//     {
//         if (pref1(ptr + 1, i) == suff1(ptr + 1, i) && pref2(ptr + 1, i) == suff2(ptr + 1, i))
//             ls = i - ptr;
//     }
//     for (ll i = n - ptr; i >= ptr + 1; i--)
//     {
//         if (pref1(i, n - ptr) == suff1(i, n - ptr) && pref2(i, n - ptr) == suff2(i, n - ptr))
//             rs = n - ptr - i + 1;
//     }

//     string ans = "";
//     if (ls >= rs)
//         ans = str.substr(0, ptr + ls) + str.substr(n - ptr, ptr);
//     else
//         ans = str.substr(0, ptr) + str.substr(n - ptr - rs, ptr + rs);
//     return ans;
// }

// int main()
// {

//     speed();

//     ll t;
//     cin >> t;

//     deg1[0] = 1, deg2[0] = 1;
//     for (ll i = 1; i < 1000002; i++)
//     {
//         deg1[i] = (deg1[i - 1] * 31) % mod;
//         deg2[i] = (deg2[i - 1] * 61) % mod;
//     }

//     while (t--)
//     {
//         string str;
//         cin >> str;
//         cout << solve(str) << endl;
//     }
//     return 0;
// }
