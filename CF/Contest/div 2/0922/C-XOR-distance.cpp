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
    ll a, b, r;
    cin >> a >> b >> r;
    
    bool f = false;
    ll mask = 0;

    for(ll i = 63; i >= 0; i--) {
        ll b1 = (a >> i) & 1;
        ll b2 = (b >> i) & 1;
        if(b1 == b2) continue;
        if(!f) {
            if(b2) swap(a , b);
            f = true;
        }
        else {
            if(b1 == 1 && (mask + (1LL << i) <= r)) mask |= (1LL << i);
        }
    }

    cout << abs((a ^ mask) - (b ^ mask)) << endl;
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