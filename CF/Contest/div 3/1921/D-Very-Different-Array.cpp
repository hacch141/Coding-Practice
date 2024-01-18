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
    vll a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll p1 = 0, p2 = n-1, q1 = 0, q2 = m-1, ans = 0;
    rep(i, 0, n) {
        ans += max(abs(a[p1] - b[q2]) , abs(a[p2] - b[q1]));
        abs(a[p1] - b[q2]) >= abs(a[p2] - b[q1]) ? (p1++, q2--) : (p2--, q1++);
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