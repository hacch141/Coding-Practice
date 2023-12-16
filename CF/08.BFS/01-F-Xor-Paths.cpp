// https://codeforces.com/problemset/problem/1006/F

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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

ll mat[20][20];
map<ll,ll> cnt[25][25];

ll n, m, k, ans = 0;

void dfs(ll i, ll j, ll& sumij, ll val) {
    val ^= mat[i][j];
    cnt[i][j][val]++;
    if(i + j == sumij) return;
    
    if(i+1 < n) dfs(i+1, j, sumij, val);
    if(j+1 < m) dfs(i, j+1, sumij, val);
}

void revdfs(ll i, ll j, ll& sumij, ll val) {
    if(i + j == sumij) {
        ans += cnt[i][j][k ^ val];
        return;
    }
    val ^= mat[i][j];
    if(i-1 >= 0) revdfs(i-1, j, sumij, val);
    if(j-1 >= 0) revdfs(i, j-1, sumij, val);
}

void solve() {
    cin >> n >> m >> k;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> mat[i][j];
        }
    }
    ll sumij = (n + m - 1) >> 1;
    dfs(0, 0, sumij, 0);
    revdfs(n-1, m-1, sumij, 0);
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}
