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
    vll a(n), clo(n);
    rep(i, 0, n) cin >> a[i];

    clo[0] = 1;
    clo[n-1] = n-2;
    rep(i, 1, n-1) {
        clo[i] = (abs(a[i] - a[i-1]) < abs(a[i] - a[i+1])) ? i - 1 : i + 1;
    }

    vll pref(n,0), suff(n,0);
    rep(i, 0, n-1) {
        pref[i+1] = pref[i] + ((clo[i] == i+1) ? 1 : abs(a[i] - a[i+1]));
    }
    for(ll i = n-1; i>0; i--) {
        suff[i-1] = suff[i] + ((clo[i] == i-1) ? 1 : abs(a[i] - a[i-1]));
    }

    ll m;
    cin >> m;
    while(m--) {
        ll x, y, ans = 0;
        cin >> x >> y;
        x--;y--;
        if(x < y) ans = pref[y] - pref[x];
        else ans = suff[y] - suff[x];
        cout << ans << endl;
    }
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