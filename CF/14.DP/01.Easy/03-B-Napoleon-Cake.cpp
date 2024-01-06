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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vll a(n,0), ans(n,0);
        rep(i, 0, n) cin >> a[i];

        ll prev = 0;
        rrep(i,0,n) {
            if(prev > 0 || a[i] > 0) {
                ans[i] = 1;
            }
            prev = max(prev,a[i]);
            prev--;
        }

        for(auto i : ans) cout << i << " ";
        cout << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}