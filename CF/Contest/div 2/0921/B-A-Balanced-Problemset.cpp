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
    ll x, n;
    cin >> x >> n;
    ll n2 = x;
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(i >= n) n2 = min(n2 , i);
            if(x / i >= n) n2 = min(n2 , x / i);
        }
    }
    cout << x / n2 << endl;
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