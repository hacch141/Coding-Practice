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

#define M 30001

ll gems[M];
ll dp[M][501];

ll n, d, p, mx;

void solve() {
    cin >> n >> d;
    while(n--) {
        cin >> p;
        gems[p]++;
        mx = max(mx, p);
    }
    
    memset(dp,-1,sizeof(dp));
    ll ans = dp[d][250] = gems[d];

    rep(i, d+1, mx+1) {
        rep(j, 0, 501) {
            ll jj = d + (j - 250);
            
            if(i - jj < 0 || jj <= 0) continue;

            if(j-1 >= 0 && dp[i-jj][j-1] != -1) dp[i][j] = max(dp[i][j], gems[i] + dp[i - jj][j-1]);
            if(dp[i-jj][j] != -1 ) dp[i][j] = max(dp[i][j], gems[i] + dp[i - jj][j]);
            if(j+1 <= 500 && dp[i-jj][j+1] != -1) dp[i][j] = max(dp[i][j], gems[i] + dp[i - jj][j+1]);

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}
