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

ll MOD = 1e9+7;

void solve() {
    ll n, height = 0;
    cin >> n;

    vector<vll> dp(2, vll(n+2));
    rep(i, 0, 2) {
        rep(j, 2, n+2) {
            cin >> dp[i][j];
        }
    }

    rep(j, 2, n+2) {
        rep(i, 0, 2) {
            dp[i][j] += max(dp[(i+1) % 2][j-1] , dp[(i+1) % 2][j-2]);
        }
    }

    cout << max(dp[0][n+1], dp[1][n+1]) << endl;
}

int main() {
    speed;
    solve();
    return 0;
}