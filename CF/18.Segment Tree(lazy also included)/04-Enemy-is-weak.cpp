#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false);

class SegmentTree {
    vll tree;
    vll &arr;

    public:
    SegmentTree(vll& a) : arr(a) {
        tree.resize(4*a.size(),0);
        BuildTree(0, 0, a.size()-1);
    }

    void BuildTree(ll ind, ll ss, ll se) {
        if(ss == se) {
            tree[ind] = arr[ss];
            return;
        }

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        BuildTree(lc, ss, mid);
        BuildTree(rc, mid+1, se);

        tree[ind] = tree[lc] + tree[rc];
        return;
    }

    void Update(ll ind, ll ss, ll se, ll i, ll val) {
        if(ss == se) {
            tree[ind] += val;
            arr[i] += val;
            return;
        }

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        if(i <= mid) Update(lc, ss, mid, i, val);
        else Update(rc, mid+1, se, i, val);

        tree[ind] = tree[lc] + tree[rc];
    }

    ll getSum(ll ind, ll ss, ll se, ll qs, ll qe) {
        if(se < qs || qe < ss) return 0;

        if(ss == se || (qs<=ss && se<=qe)) return tree[ind];

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;

        return getSum(lc, ss, mid, qs, qe) + getSum(rc, mid+1, se, qs, qe);;
    }
};

int main() {

    speed();
    cin.tie(NULL);

    ll n;
    cin >> n;

    vll a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    vll newa = a;
    sort(a.begin(),a.end());
    for(ll i=0; i<n; i++) {
        newa[i] = lower_bound(a.begin(),a.end(),newa[i]) - a.begin();
    }
    
    vll t1(n,0), t2(n,1);
    SegmentTree ST1(t1), ST2(t2);

    ll ans = 0;
    for(ll i=0; i<n; i++) {
        ST2.Update(0,0,n-1,newa[i],-1);
        ll left = ST1.getSum(0,0,n-1,newa[i]+1,n-1);
        ll right = ST2.getSum(0,0,n-1,0,newa[i]-1);
        ans += left*right;
        ST1.Update(0,0,n-1,newa[i],+1);
    }

    cout << ans << endl;

    return 0;
}