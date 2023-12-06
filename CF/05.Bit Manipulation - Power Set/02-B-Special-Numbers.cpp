#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll mod = 1e9+7;

ll numpow(ll n, ll pow) {
    ll ans = 1;
    while(pow) {
        if(pow&1) {
            ans = (ans*n) % mod;
        }
        n = (n*n) % mod;
        pow >>= 1;
    }
    return ans;
}

int main() {

    speed();

    ll t;
    cin >> t;
    while(t--) {
        ll n, k, bit = 0, ans = 0;
        cin >> n >> k;
        while(k > 0) {
            if(k&1) {
                ans = (ans + (numpow(n,bit))) % mod;
            }
            k >>= 1;
            bit++;
        }
        cout << ans << endl;
    }

    return 0;
}