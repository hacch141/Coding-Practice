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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll a(n+1), dp(n+1,1);
        rep(i, 1, n+1) cin >> a[i];

        ll mxLen = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = i; j <= n; j+=i) {
                if(a[j] > a[i]) {
                    dp[j] = max(dp[j], 1 + dp[i]);
                    mxLen = max(mxLen,dp[j]);
                }
            }
        }

        cout << (mxLen != 0 ? mxLen : 1) << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}