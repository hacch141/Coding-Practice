#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

bool isValid(vll& a, ll k, ll H) {
    ll d = k;
    for(ll i=0; i<a.size()-1; i++) {
        d += min(a[i+1]-a[i],k);
    }
    return d >= H;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, H;
        cin >> n >> H;

        vll a(n);
        for(ll i=0; i<n; i++) cin >> a[i];

        ll l = 0, h = H, ans = 0;
        while(l <= h) {
            ll m = (l+h)/2;
            if(isValid(a,m,H)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
