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
    string a, b, c;
    cin >> n >> a >> b >> c;
    rep(i, 0, n) {
        if((a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) || (a[i] == b[i] && b[i] != c[i])) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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