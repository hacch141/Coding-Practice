#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<long long>
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for (ll i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)

#define speed ios_base::sync_with_stdio(false), cin.tie(NULL);

// unordered_map<string,vector<string>> mp;
// unordered_map<string,ll> indegree;
// ll ans = 0;

// void bfs(string start) {
//     queue<string> q;
//     q.push(start);
//     ll lev = 0;
//     while(!q.empty()) {
//         ll size = q.size();
//         rep(i, 0, size) {
//             string u = q.front();
//             q.pop();
//             trav(v, mp[u]) {
//                 q.push(v);
//             }
//         }
//         lev++;
//     }
//     ans = max(ans,lev);
// }

// void solve() {
//     ll n;
//     cin >> n;
//     while(n--) {
//         string v, reposted, u;
//         cin >> v >> reposted >> u;
//         transform(u.begin(), u.end(), u.begin(), ::tolower);
//         transform(v.begin(), v.end(), v.begin(), ::tolower);
//         mp[u].push_back(v);
//         indegree[v]++;
//         if(indegree.find(u) == indegree.end()) indegree[u] = 0;
//     }

//     trav(u, indegree) {
//         if(u.second == 0) {
//             bfs(u.first);
//         }
//     }

//     cout << ans << endl;
// }

void solve() {
    ll n, ans = 0;
    cin >> n;
    unordered_map<string, ll> mp;
    while (n--) {
        string v, reposted, u;
        cin >> v >> reposted >> u;
        transform(u.begin(), u.end(), u.begin(), ::tolower);
        transform(v.begin(), v.end(), v.begin(), ::tolower);
        mp[v] = 1 + mp[u];
        ans = max(ans,mp[v]);
    }
    cout << ans + 1 << endl;
}

int main()
{
    speed;
    solve();
    return 0;
}