// https://cses.fi/problemset/task/1130

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

vll tree[200002];
ll dp[200002][2];

ll dfs(ll u, bool isTake, ll p) {
    if(dp[u][isTake] != -1) return dp[u][isTake];
    
    ll ans = 0;

    trav(v, tree[u]) {
        if(v != p) ans += dfs(v, 1, u);
    }

    if(!isTake) return dp[u][isTake] = ans;

    ll mx = 0;
    trav(v, tree[u]) {
        if(v != p) mx = max(mx, ans - dfs(v, 1, u) + dfs(v, 0, u) + 1);
    }

    return dp[u][isTake] = mx;
}

void solve() {
    ll n;
    cin >> n;
    rep(i, 1, n) {
        ll u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    cout << max(dfs(1, 0, -1), dfs(1, 1, -1)) << endl;
}

int main() {
    speed;
    memset(dp, -1, sizeof(dp));
    solve();
    return 0;
}
