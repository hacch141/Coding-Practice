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
    ll n;
    cin >> n;

    vll a(n), b(n), v(n+1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        cin >> b[i];
        v[a[i]] = b[i];
    }

    rep(i, 1, n + 1) cout << i << " ";
    cout << endl;
    rep(i, 1, n + 1) cout << v[i] << " ";
    cout << endl;
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