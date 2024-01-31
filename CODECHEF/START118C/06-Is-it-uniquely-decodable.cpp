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

ll mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    ll n = s.length(), a = 0, ab = 0, ba = 0;

    rep(i, 0, n) {
        if(s[i] == 'a') {
            a += (a + 1);
            a %= mod;
            ba += ab;
            ba %= mod;
        }
        else {
            ab += (a + ba);
            ab %= mod;
        }
    }

    cout << (a + ab) % mod << endl;
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