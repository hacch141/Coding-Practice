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
    ll n, k, m;
    string s;
    cin >> n >> k >> m >> s;

    string ans = "";
    unordered_set<char> st;
    rep(i, 0, m) {
        st.insert(s[i]);
        if(st.size() == k) {
            ans.pb(s[i]);
            st.clear();
        }
    }

    if(ans.length() >= n) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
        char ch;
        rep(i, 0, k) {
            if(!st.count(i + 'a')) {
                ch = i + 'a';
                break;
            }
        }
        while(ans.length() != n) {
            ans.pb(ch);
        }
        cout << ans << endl;
    }
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