// https://cses.fi/problemset/task/1674/

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

void dfs(ll u, vll& ans) {
    ll subordinates = 0;
    trav(v, tree[u]) {
        dfs(v, ans);
        subordinates += (1 + ans[v]);
    }
    ans[u] = subordinates;
}

void solve() {
    ll n;
    cin >> n;
    rep(v, 2, n+1) {
        ll u;
        cin >> u;
        tree[u].pb(v);
    }
    vll ans(n,0);
    dfs(1,ans);
    rep(i, 1, n+1) cout << ans[i] << " ";
}

int main() {
    speed;
    solve();
    return 0;
}
