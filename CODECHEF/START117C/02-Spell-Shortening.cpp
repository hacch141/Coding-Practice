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
    string s;
    cin >> s;

    int ind = -1;
    rep(i, 0, n-1) {
        if(s[i] > s[i+1]) {
            ind = i;
            break;
        }
    }

    string ans = s;
    if(ind != -1) {
        ans = s.substr(0,ind) + s.substr(ind+1);
    }
    else {
        ans.pop_back();
    }
    cout << ans << endl;
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