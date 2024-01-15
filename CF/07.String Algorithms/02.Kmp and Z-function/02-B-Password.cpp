#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<long long>
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for (ll i = (b) - 1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
 
#define speed ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(1000005), pw2(1000005);

vll kmp(string& s) {
    ll n = s.length();
    vll lps(n, 0);

    rep(i, 1, n) {
        ll prev_ind = lps[i -1];
        while(prev_ind > 0 && s[i] != s[prev_ind]) {
            prev_ind = lps[prev_ind - 1];
        }
        lps[i] = prev_ind + (s[i] == s[prev_ind]);
    }

    return lps;
}

void solve() {
    string s;
    cin >> s;

    ll n = s.length();
    pw1[0] = 1, pw2[0] = 1;
    for(ll i=1; i<n; i++) {
        pw1[i] = (pw1[i-1]*base1) % mod1;
        pw2[i] = (pw2[i-1]*base2) % mod2;
    }

    ll mp[n] = {0};
    
    ll h1 = 0, h2 = 0, h3 = 0, h4 = 0, len1 = 0, len2 = 0;
    rep(i, 0, n - 1) {
        h1 = (((h1 * base1) % mod1) + (s[i] - 'a' + 1)) % mod1;
        h2 = (h2 + ((s[n - 1 - i] - 'a' + 1) * pw1[i]) % mod1) % mod1;

        h3 = (((h3 * base2) % mod2) + (s[i] - 'a' + 1)) % mod2;
        h4 = (h4 + ((s[n - 1 - i] - 'a' + 1) * pw2[i]) % mod2) % mod2;

        if(h1 == h2 && h3 == h4) {
            mp[i+1] = 1;
        }
    }

    vll lps = kmp(s);
    ll len = 0;
    rep(i, 0, lps.size() - 1) {
        if(mp[lps[i]]) {
            len = max(len, lps[i]);
        }
    }

    cout << (len > 0 ? s.substr(0, len) : "Just a legend") << endl;
}
 
int main() {
    speed;
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
}