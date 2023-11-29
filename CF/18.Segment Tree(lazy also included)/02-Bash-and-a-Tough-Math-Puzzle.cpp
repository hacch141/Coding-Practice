#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

class Segment {
    vll tree;
    vll arr;
    public:
    Segment(vll& a, ll& n) {
        tree.resize(4*n);
        arr = a;
        BuildTree(0,0,n-1);
    }

    void BuildTree(ll ind, ll ss, ll se) {
        if(ss == se) {
            tree[ind] = arr[ss];
            return;
        }

        ll mid = (ss+se)/2, lc = 2*ind + 1, rc = 2*ind + 2;
        BuildTree(lc, ss, mid);
        BuildTree(rc, mid+1, se);

        tree[ind] = __gcd(tree[lc],tree[rc]);
    }

    void Update(ll ind, ll ss, ll se, ll i, ll val) {
        if(ss == se) {
            tree[ind] = val;
            arr[i] = val;
            return;
        }

        ll mid = (ss+se)/2, lc = 2*ind + 1, rc = 2*ind + 2;
        if(i <= mid) Update(lc, ss, mid, i, val);
        else Update(rc, mid+1, se, i, val);

        tree[ind] = __gcd(tree[lc],tree[rc]);
    }

    bool query(ll ind, ll ss, ll se, ll qs, ll qe, ll x, bool& flag) {
        if(se < qs || qe < ss || tree[ind]%x==0) return true;

        if(ss == se) {
            if(qs<=ss && se<=qe) {
                if(flag) return false;
                flag = true;
                return true;
            }
            return true;
        }

        ll mid = (ss+se)/2, lc = 2*ind + 1, rc = 2*ind + 2;
        bool l = query(lc, ss, mid, qs, qe, x, flag);
        if(!l) return false;
        bool r = query(rc, mid+1, se, qs, qe, x, flag);
        return l && r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    vll a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    Segment st(a,n);

    ll q;
    cin >> q;

    while(q--) {
        ll qtype;
        cin >> qtype;
        if(qtype == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            bool flag = false;
            cout << (st.query(0,0,n-1,l,r,x,flag) ? "YES" : "NO") << endl;
        }
        else {
            ll i, y;
            cin >> i >> y;
            i--;
            st.Update(0,0,n-1,i,y);
        }
    }

    return 0;
}