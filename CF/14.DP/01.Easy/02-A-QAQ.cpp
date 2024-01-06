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

// ll rec(ll ind, string& str, ll curr, vector<vll>& dp) {
//     if(curr == 3) return 1;
//     if(ind == str.length()) return 0;

//     if(dp[ind][curr] != -1) return dp[ind][curr];

//     ll take = 0, nottake = 0;
//     if((curr%2 == 0 && str[ind] == 'Q') || (curr%2 == 1 && str[ind] == 'A')) {
//         take = rec(ind+1, str, curr+1, dp);
//     }
//     nottake = rec(ind+1, str, curr, dp);
//     return dp[ind][curr] = take + nottake;
// }

void solve() {
    string s, str;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'Q' || s[i] == 'A') str += s[i];
    }

    ll n = str.length();
    // vector<vll> dp(n+1, vll(3,-1));
    // cout <<  rec(0, str, 0, dp) << endl;
    // return;

    ll cntQ = 0, cntQA = 0, ans = 0;
    rep(i, 0, n) {
        if(str[i] == 'Q') {
            ans += cntQA;
            cntQ++;
        }
        if(str[i] == 'A') {
            cntQA += cntQ;
        }
    }

    cout << ans << endl;
    return;
}

int main() {
    speed;
    solve();
    return 0;
}