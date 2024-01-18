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
    rep(i, 0, n) {
        cin >> a[i];
        a[i] = (1 << a[i]);
    }
    sort(a.begin(),a.end());

    ll ans = 0;
    rep(i, 0, n) {
        rep(j, i+1, n-1) {
            ll d = abs(a[i] - a[j]);
            ll end = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin();
            ans += (end - (j + 1));
        }
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