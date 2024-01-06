// A. Maximum Increase

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

void solve(vll& a, ll& n) {
    ll ans = 0, curr = 1;
    rep(i,1,n) {
        if(a[i] > a[i-1]) {
            curr++;
        }
        else {
            ans = max(ans,curr);
            curr = 1;
        }
    }
    ans = max(ans,curr);
    cout << ans << endl;
    return;
}

int main() {
    speed;
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n) cin >> a[i];
    solve(a, n);
    return 0;
}
