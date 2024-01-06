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

void solve() {
    string s;
    cin >> s;

    ll n = s.length();
    vll freq(n,0);
    if(s[0] == s[1]) freq[0] = 1;
    rep(i, 1, n-1) {
        freq[i] = freq[i-1];
        if(s[i] == s[i+1]) {
            freq[i]++;
        }
    }

    ll m;
    cin >> m;
    while(m--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        if(l == 0) cout << freq[r-1] << endl;
        else cout << freq[r-1] - freq[l-1] << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}