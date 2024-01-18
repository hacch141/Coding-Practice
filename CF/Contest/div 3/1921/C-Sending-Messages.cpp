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
    ll n, f, a, b, m, st, on, off_on;
    cin >> n >> f >> a >> b;
    st = 0;
    rep(i, 0, n) {
        cin >> m;
        on = a * (m - st);
        off_on = b;
        st = m;
        f -= min(on, off_on);
    }
    cout << (f > 0 ? "YES" : "NO") << endl;
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