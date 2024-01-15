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
    ll n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;

    string str = t + "#" + s;
    vll lps = kmp(str);

    while(q--) {
        ll l, r, ans = 0;
        cin >> l >> r;
        l += m;
        r += m;
        rep(i, l, r+1) {
            if(lps[i] == m && i - m + 1 >= l) {
                ans++;
            }
        }
        cout << ans << endl;
    }
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
