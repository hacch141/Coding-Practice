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

    if(n > m) swap(n, m);

    ll d = m / 2, ans = 0, mod = 998244353;

    ll top = max(1LL, n - d);
    ll bot = min(n, 1 + d);
    ll lf = max(1LL, m - d);
    ll rt = min(m, 1 + d);

    ll sumTB = ((bot * (bot + 1)) / 2) - (((top - 1) * top) / 2);
    sumTB %= mod;

    rep(i, lf, rt+1) {
        ans += (i * sumTB);
        ans %= mod;
    }

    cout << ans << endl;
}
 
int main() {
    speed;
    ll t;
    cin >> t;
    // t = 1;
    while(t--) {
        solve();
    }
}