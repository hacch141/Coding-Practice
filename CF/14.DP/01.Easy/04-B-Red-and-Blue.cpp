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
        vll a(n);

        ll sumA = 0, sumB = 0, mxA = 0, mxB = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sumA += a[i];
            mxA = max(mxA,sumA);
        }

        ll m;
        cin >> m;
        vll b(m);
        rep(i, 0, m) {
            cin >> b[i];
            sumB += b[i];
            mxB = max(mxB,sumB);
        }

        cout << mxA + mxB << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}