// C. Array Elimination

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

int main() {

    speed();

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vll a(n);
        for(ll i=0; i<n; i++) cin >> a[i];

        vll cnts(32,0);
        for(ll i=0; i<n; i++) {
            for(ll bit=0; bit<32; bit++) {
                if(a[i] & (1<<bit)) {
                    cnts[bit]++;
                }
            }
        }

        cout << 1 << " ";
        for(ll i=2; i<=n; i++) {
            bool f = true;
            for(ll c=0; c<32; c++) {
                if(cnts[c]%i != 0) {
                    f = false;
                    break;
                }
            }
            if(f) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
