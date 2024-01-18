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
    vector<vll> cod(4, vll(2));
    rep(i, 0, 4) {
        cin >> cod[i][0] >> cod[i][1];
    }
    ll l = 1e4;
    rep(i, 1, 4) {
        ll d = abs(cod[0][0] - cod[i][0]) + abs(cod[0][1] - cod[i][1]);
        l = min(l, d);
    }
    cout << l * l << endl;
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