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
    ll n, k;
    cin >> n >> k;
    vector<vll> dp(k+1, vll(n+1,0));
    dp[0][1] = 1;

    for(ll len = 1; len <= k; len++) {
        for(ll i = 1; i <= n; i++) {
            for(ll j = i; j <= n; j += i) {
                dp[len][j] = (dp[len][j] + dp[len-1][i]) % MOD;
            }
        }
    }

    ll ans = 0;
    rep(i, 1, n+1) {
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}