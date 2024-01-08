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

// TLE
// ll rec(ll ind, ll& n, bool isAdd, vll& a) { 
//     if(ind == n) return 0;
//     ll take = 0, nottake = 0;
//     nottake = rec(ind + 1, n, isAdd, a);
//     take = (isAdd ? a[ind] : - a[ind]) + rec(ind + 1, n, !isAdd, a);
//     return max(take,nottake);
// }

// void solve() {
//     ll t;
//     cin >> t;
//     while(t--) {
//         ll n, q;
//         cin >> n >> q;
//         vll a(n);
//         rep(i, 0, n) cin >> a[i];
//         cout << rec(0, n, true, a) << endl;
//     }
// }


void solve() {
    ll t;
    cin >> t;

    while(t--) {
        ll n, q, a;
        cin >> n >> q;
        
        vll dp(2,0);
        rep(i, 0, n) {
            cin >> a;
            dp[0] = max(dp[0], dp[1] - a);
            dp[1] = max(dp[1], dp[0] + a);
        }
        cout << dp[1] << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}