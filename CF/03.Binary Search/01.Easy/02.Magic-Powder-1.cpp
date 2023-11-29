#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

bool isValid(vll& a, vll& b, ll& n, ll k, ll& cookies) {
    ll powder = 0;
    for(ll i=0; i<n; i++) {
        if(a[i]*cookies > b[i]) {
            k -= (a[i]*cookies - b[i]);
        }
        if(k<0) return false;
    }
    return true;
}

ll main() {
    ll n, k;
    cin >> n >> k;

    vll a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    vll b(n);
    for(ll i=0; i<n; i++) {
        cin >> b[i];
    }

    ll low = 0, high = 1e10, ans = 0;

    while(low <= high) {
        ll mid = (low+high)/2;
        if(isValid(a,b,n,k,mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
