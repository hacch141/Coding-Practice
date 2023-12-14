#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(5000002), pw2(5000002);

void solve() {
    string s;
    cin >> s;
    ll n = s.length();
    s = "#" + s;

    pw1[0] = 1;
    for(ll i=1; i<=n; i++) {
        pw1[i] = (pw1[i-1]*base1) % mod1;
    }

    vll dp(n+1,0);
    ll h1 = 0, h3 = 0, ans = 0;
    for(ll i=1; i<=n; i++) {
        h1 = ((h1*base1) % mod1 + (s[i] - 'a' + 1)) % mod1;
        h3 = (h3 + ((s[i] - 'a' + 1)*pw1[i-1]) % mod1) % mod1;
        if(h1 == h3) {
            dp[i] = 1 + dp[i/2];
        }
        ans += dp[i];
    }
    cout << ans << endl;
}
 
int main() {
    speed();
    solve();
}
