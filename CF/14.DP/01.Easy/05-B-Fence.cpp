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
    ll n, k;
    cin >> n >> k;
    vll a(n);

    ll win_sum = 0, st_ind = 0, mn = INT_MAX;

    rep(i, 0, k) {
        cin >> a[i];
        win_sum += a[i];
    }


    if(win_sum < mn) {
        st_ind = 1;
        mn = win_sum;
    }

    rep(i, k, n) {
        cin >> a[i];
        win_sum += a[i];
        win_sum -= a[i-k];
        if(win_sum < mn) {
            st_ind = i - k + 2;
            mn = win_sum;
        }
    }

    cout << st_ind << endl;
    return;
}

int main() {
    speed;
    solve();
    return 0;
}