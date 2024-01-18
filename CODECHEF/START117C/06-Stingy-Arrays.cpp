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
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    vll b;
    ll cnt = 0;
    while(a.size() != 0 || b.size() != 0) {
        rep(i, 1, a.size()) {
            if(a[i] == a[i-1]) b.pb(a[i]);
        }
        cnt++;
        a = b;
        b.clear();
    }
    cout << (cnt % 2 == 1 ? "Alice" : "Bob") << endl;
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