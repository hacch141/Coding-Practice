#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

class Segment {
    vll tree;
    vll arr;
    public:
    Segment(ll n) {
        tree.resize(4*n,0);
        arr.resize(n,0);
    }

    void Update(ll ind, ll ss, ll se, ll i, ll val) {
        if(ss == se) {
            tree[ind] += val;
            arr[i] += val;
            return;
        }

        ll mid = (ss+se)/2, lc = 2*ind + 1, rc = 2*ind + 2;
        if(i <= mid) Update(lc, ss, mid, i, val);
        else Update(rc, mid+1, se, i, val);

        tree[ind] = tree[lc] + tree[rc];
    }

    ll Query(ll ind, ll ss, ll se, ll qs, ll qe) {
        if(se < qs || qe < ss) return 0;

        if(ss == se || (qs<=ss && se<=qe)) return tree[ind];

        ll mid = (ss+se)/2, lc = 2*ind + 1, rc = 2*ind + 2;

        ll l = Query(lc, ss, mid, qs, qe);
        ll r = Query(rc, mid+1, se, qs, qe);

        return l + r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vll a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    vll pref(n,0), suff(n,0);
    unordered_map<ll,ll> mp;
    for(ll i=0; i<n; i++) {
        mp[a[i]]++;
        pref[i] = mp[a[i]];
    }

    mp.clear();

    for(ll i=n-1; i>=0; i--) {
        mp[a[i]]++;
        suff[i] = mp[a[i]];
    }

    Segment st(n);

    ll ans = 0;
    for(ll i=n-1; i>=0; i--) {
        ans += st.Query(0,0,n-1,0,pref[i]-2);
        st.Update(0,0,n-1,suff[i]-1,1);
    }

    cout << ans << endl;

    return 0;
}