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

bool ok(ll a, ll b, vector<vll>& freq) {
    return (freq[a][0] >= freq[b][0]) && (freq[a][1] >= freq[b][1]);
}

void solve() {
    string s, t;
    cin >> s >> t;

    ll n = s.length(), m = t.length();

    vector<vll> freq(3, vll(2,0));
    trav(i, s) freq[0][i-'0']++;
    trav(i, t) freq[1][i-'0']++;

    vll lps = kmp(t);
    string partial = t.substr(lps[m-1]);
    trav(i, partial) freq[2][i-'0']++;

    string ans;
    if(ok(0, 1, freq)) {
        freq[0][0] -= freq[1][0];
        freq[0][1] -= freq[1][1];
        ans = t;
    }

    while(ok(0, 2, freq)) {
        freq[0][0] -= freq[2][0];
        freq[0][1] -= freq[2][1];
        ans += partial;
    }

    while(freq[0][0]--) {
        ans += "0";
    }

    while(freq[0][1]--) {
        ans += "1";
    }

    cout << ans << endl;
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