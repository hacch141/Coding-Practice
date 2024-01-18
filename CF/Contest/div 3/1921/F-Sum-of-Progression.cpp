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
#define D 300
ll pref[D][100000 + D], pref2[D][100000 + D];

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    rep(d, 1, D) {
        rep(i, 0, n) {
            pref[d][i + d] = pref[d][i] + a[i];
            pref2[d][i + d] = pref2[d][i] + a[i]*(1 + (i / d));
        }
    }
    
    while(q--) {
        ll s, d, k, ans = 0;
        cin >> s >> d >> k;
        s--;
        ll e = s + (k * d);
        if(d < D) {
            ans += pref2[d][e] - pref2[d][s];
            ans -= ((pref[d][e] - pref[d][s]) * (s / d));
        }
        else {
            rep(i, 0, k) {
                ans += (a[s + (i * d)] * (i + 1));
            }
        }
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