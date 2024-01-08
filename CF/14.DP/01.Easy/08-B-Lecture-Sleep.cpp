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
    ll n, k;
    cin >> n >> k;
    vll a(n), t(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> t[i];

    ll theorems = 0;
    rep(i, 0, n) {
        if(t[i] == 1) {
            theorems += a[i];
        }
    }

    ll win = 0, mx = 0;
    rep(i, 0, k) {
        if(t[i] == 0) {
            win += a[i];
        }
    }

    mx = win;

    rep(i, k, n) {
        if(t[i] == 0) win += a[i];
        if(t[i-k] == 0) win -= a[i-k];
        mx = max(mx,win);
    }

    cout << theorems + mx << endl;
}

int main() {
    speed;
    solve();
    return 0;
}