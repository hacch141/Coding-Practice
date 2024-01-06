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
    vll a(n);

    ll cnt_0 = 0, cnt_1 = 0, mx_len = 0, l = 0, r = 0, ans = 0, maybe = -1;
    rep(i, 0, n) {
        cin >> a[i];
        if(a[i] == 1) {
            cnt_1++;
            ans++;
        }
        else {
            cnt_0++;
        }

        if(cnt_0 > cnt_1) {
            maybe = max(maybe, cnt_0 - cnt_1);
        }

        if(cnt_0 < cnt_1) {
            l = i+1;
            r = i;
            cnt_0 = 0;
            cnt_1 = 0;
        }
        r++;
    }
    cout << ans + maybe << endl;
}

int main() {
    speed;
    solve();
    return 0;
}