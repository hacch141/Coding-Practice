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
    ll a, b;
    cin >> a >> b;
    
    ll diff = abs(a - b);
    ll l = 0, h = diff, n;
    while(l <= h) {
        ll mid = (h - l) / 2 + l;
        if((mid * (mid+1)) / 2 <= diff) {
            n = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    ll sum = (n * (n + 1) / 2);
    if(sum == diff) {
        cout << n << endl;
        return;
    }

    rep(i, 0, 3) {
        n++;
        sum += n;
        if((sum - diff) % 2 == 0) {
            cout << n << endl;
            return;
        }
    }

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