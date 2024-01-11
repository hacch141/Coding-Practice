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

// ll helper(ll num) {
//     if(num < 10) return num;
//     ll ans = (num / 10) + 9;
//     ll last = num % 10;
//     ll first = num;
//     while(first > 9) first /= 10;
//     if(first > last) ans--;
//     return ans;
// }

// void solve() {
//     ll l, r;
//     cin >> l >> r;
//     cout << helper(r) - helper(l-1) << endl;
// }

ll dp[19];

void makeDP() {
    dp[0] = 0;
    dp[1] = 9;
    rep(i, 2, 19) {
        dp[i] = (dp[i-1] + (9 * pow(10 , i-2)));
    }
}

ll find(ll num) {
    vll digits;
    while(num) {
        digits.pb(num%10);
        num /= 10;
    }
    reverse(digits.begin(),digits.end());

    ll n = digits.size();

    if(n == 0) return 0;
    if(n == 1) return digits[0];

    ll ans = dp[n - 1];
    ans += (digits[0] - 1) * pow(10, n - 2);

    ll last = 0;
    rep(i, 1, n-1) {
        last = (last*10) + digits[i];
    }

    ans += last + 1;
    if(digits[0] > digits[n-1]) ans--;

    return ans;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    makeDP();
    cout << find(r) - find(l-1) << endl;
}

int main() {
    speed;
    solve();
    return 0;
}