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

bool ok_right(ll l, ll r, ll steps, ll w) {
    return (l + steps) >= w;
}

bool ok_left(ll l, ll r, ll steps, ll w) {
    return (r - steps) <= 1;
}

string solve() {
    ll h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa >= xb) return "DRAW";
    string who = abs(xa - xb) % 2 ? "ALICE" : "BOB";

    ll steps = abs(xa- xb)/2;
    if((abs(ya - yb) <= 1 && who == "ALICE") || (abs(ya - yb) == 0)) {
        return who;
    }
    else {
        if(who == "ALICE") {
            if(ya < yb) {
                return ok_right(ya + 1, yb, steps, w) ? who : "DRAW";
            }
            if(ya > yb) {
                return ok_left(yb, ya - 1, steps, w) ? who : "DRAW";
            }
        }
        else {
            if(ya < yb) {
                return ok_left(ya, yb, steps, w) ? who : "DRAW";
            }
            if(ya > yb) {
                return ok_right(yb, ya, steps, w) ? who : "DRAW";
            }
        }
    }
    return "DRAW";
}
 
int main() {
    speed;
    ll t;
    cin >> t;
    // t = 1;
    while(t--) {
        cout << solve() << endl;
    }
}