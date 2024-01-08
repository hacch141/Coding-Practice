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

// TLE
// ll rec(ll total, ll& n, ll& a, ll&b, ll& c) {
//     if(total == n) return 0;
//     if(total > n) return -1e9;

//     ll ans = -1e9;

//     ans = max(ans, 1 + rec(total + a, n, a, b, c));
//     ans = max(ans, 1 + rec(total + b, n, a, b, c));
//     ans = max(ans, 1 + rec(total + c, n, a, b, c));

//     return ans;
// }

// void solve() {
//     ll n, a, b, c;
//     cin >> n >> a >> b >> c;
//     cout << rec(0, n, a, b, c) << endl;
// }

void solve() {
    ll n;
    vll a(3);
    cin >> n >> a[0] >> a[1] >> a[2];

    vll dp(n+1, -1);
    dp[0] = 0;

    rep(i, 0, 3) {
        rep(j, a[i], n+1) {
            if(dp[j - a[i]] != -1) dp[j] = max(dp[j], 1 + dp[j - a[i]]);
        }
    }

    cout << dp[n] << endl;
}

int main() {
    speed;
    solve();
    return 0;
}