// https://codeforces.com/gym/102694/problem/C

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

vll tree[300002];
ll up[300002][20];
ll height[300002];

void binary_lifting(ll u, ll par) {
    up[u][0] = par;
    rep(i, 1, 20) {
        if(up[u][i-1] != -1) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
        else {
            up[u][i] = -1;
        }
    }

    trav(v, tree[u]) {
        if(v != par) {
            height[v] = 1 + height[u];
            binary_lifting(v, u);
        }
    }
}

ll get_kth_ancestor(ll node, ll jump) {
    rrep(i, 0, 20) {
        if(jump & (1<<i)) node = up[node][i];
        if(node == -1) break;
    }   
    return node;
}

ll get_LCA(ll a, ll b) {
    if(height[a] < height[b]) {
        swap(a,b);
    }
    ll diff = height[a] - height[b];
    rrep(i, 0, 20) {
        if(diff & (1<<i)) a = up[a][i];
    }
    if(a == b) return a;
    rrep(i, 0, 20) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
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
    
    height[1] = 0;
    binary_lifting(1, -1);

    ll q;
    cin >> q;
    while(q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll lca = get_LCA(a, b);
        
        ll l = height[a] - height[lca], r = height[b] - height[lca];
        if(c <= l) {
            cout << get_kth_ancestor(a, c) << endl;
        }
        else if(c < l + r) {
            cout << get_kth_ancestor(b, l + r - c) << endl;
        }
        else {
            cout << b << endl;
        }
    }
}

int main() {
    speed;
    solve();
    return 0;
}
