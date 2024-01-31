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
    ll x, l;
    cin >> x;

    ll n1 = 0 , n2 = 0, c = 0;
    bool f = true;

    rrep(i, 0, 33) {
        if(f && ((x >> i) & 1)) {
            n1 = (1 << i);
            f = false;
        }
        else {
            if((x >> i) & 1) {
                n2 |= (1 << i);
            }
        }
    }

    rep(i, 0, 31) {
        if((x & (1 << i)) == 0) {
            if((n1 + (1 << i)) <= x && (n2 + (1 << i)) <= x) {
                c++;
            }
        }
    }
    
    cout << (1 << c) << endl;
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