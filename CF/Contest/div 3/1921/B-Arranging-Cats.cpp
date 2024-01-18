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
    string s1, s2;
    cin >> s1 >> s2;

    ll c1 = 0, c2 = 0;
    rep(i, 0, n) {
        if(s1[i] == '0' && s2[i] == '1') c1++;
        else if(s1[i] == '1' && s2[i] == '0') c2++;
    }
    cout << max(c1, c2) << endl;
}
 
int main() {
    speed;
    ll t;
    cin >> t;
    // t = 1;
    while(t--) {
        solve();
    }
}