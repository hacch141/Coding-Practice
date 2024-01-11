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
    ll n, m;
    cin >> n >> m;
    vll a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] %= m;
    }

    if(n > m) {
        cout << "YES" << endl;
        return;
    }

    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));

    // rep(i, 1, n+1) {
    //     rep(r, 0, m+1) {
    //         dp[i][(r + a[i-1]) % m] = (dp[i-1][r] || dp[i-1][(r + a[i-1]) % m]);
    //     }
    //     dp[i][a[i-1]] = true;
    // }

    rep(i, 1, n+1) {
        rep(r, 0, m) {
            dp[i][r] = (dp[i-1][r] || dp[i-1][(r - a[i-1] + m) % m]);
        }
        dp[i][a[i-1]] = true;
    }

    if(dp[n][0]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    speed;
    solve();
    return 0;
}