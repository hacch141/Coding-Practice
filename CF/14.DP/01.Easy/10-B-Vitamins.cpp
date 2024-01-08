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

void solve() {

    ll n;
    cin >> n;

    vll all(8, 1e9);
    while(n--) {
        ll price;
        string vit;
        cin >> price >> vit;

        ll curr = 0;
        trav(i, vit) {
            curr += (1<<(i-'A'));
        }
        
        all[curr] = min(all[curr], price);

        rep(i, 1, 8) {
            all[i | curr] = min(all[i | curr], all[i] + all[curr]);
        }
    }
    cout << (all[7] != 1e9 ? all[7] : -1 ) << endl;
}

int main() {
    speed;
    solve();
    return 0;
}