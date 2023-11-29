#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

ll sum(ll x) {
    return x*(x+1)/2;
}

bool isValid(ll m, ll k, ll n) {
    return sum(k) - sum(k-m) >= n;
}

int main() {
    ll n, k;
    cin >> n >> k;

    if(n > (k*(k-1)/2 + 1)) {
        cout << "-1" << endl;
        return 0;
    }

    ll l = 0, h = k-1, ans = 0;
    n--;
    while(l <= h) {
        ll m = (l+h)/2;
        if(isValid(m,k-1,n)) {
            ans = m;
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
