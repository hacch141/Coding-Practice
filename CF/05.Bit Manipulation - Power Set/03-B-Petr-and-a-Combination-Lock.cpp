// B. Petr and a Combination Lock

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

int main() {

    speed();

    ll n;
    cin >> n;
    vll a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
 
    for(ll mask=1; mask < (1<<n); mask++) {
        ll total = 0;
        for(ll bit=0; bit<n; bit++) {
            if(mask & (1<<bit)) {
                total += a[bit];
            }
            else {
                total -= a[bit];
            }
        }
        if(total == 0 || total%360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
