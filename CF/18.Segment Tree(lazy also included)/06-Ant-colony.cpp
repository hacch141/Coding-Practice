#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);;

struct Node {
    ll mn, t;
};

class SegmentTree {
    vll treeGCD;
    vector<Node> treeMIN;
    vll arr;

    public:
    SegmentTree(vll& a) {
        ll n = a.size();
        treeGCD.resize(4*n);
        treeMIN.resize(4*n);
        arr = a;
        BuildTree(0,0,n-1);
    }

    Node getMin(Node n1, Node n2) {
        Node n;
        if(n1.mn == n2.mn) {
            n.mn = n1.mn;
            n.t = n1.t + n2.t;
        }
        else if(n1.mn < n2.mn) {
            return n1;
        }
        else {
            return n2;
        }
        return n;
    }

    void BuildTree(ll ind, ll ss, ll se) {
        if(ss == se) {
            treeGCD[ind] = arr[ss];
            treeMIN[ind].mn = arr[ss];
            treeMIN[ind].t = 1;
            return;
        }

        ll mid = (ss+se)/2, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        BuildTree(lc, ss, mid);
        BuildTree(rc, mid+1, se);

        treeGCD[ind] = __gcd(treeGCD[lc],treeGCD[rc]);
        treeMIN[ind] = getMin(treeMIN[lc],treeMIN[rc]);
        return;
    }

    Node getMin(ll ind, ll ss, ll se, ll qs, ll qe) {
        if(se < qs || qe < ss) return {INT_MAX,0};

        if(qs <= ss && se <= qe) return treeMIN[ind];

        ll mid = (ss+se)/2, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        Node left = getMin(lc, ss, mid, qs, qe);
        Node right = getMin(rc, mid+1, se, qs, qe);

        return getMin(left,right);
    }

    ll getGCD(ll ind, ll ss, ll se, ll qs, ll qe) {
        if(se < qs || qe < ss) return 0;

        if(qs <= ss && se <= qe) return treeGCD[ind];

        ll mid = (ss+se)/2, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        ll left = getGCD(lc, ss, mid, qs, qe);
        ll right = getGCD(rc, mid+1, se, qs, qe);

        return __gcd(left,right);
    }
};

int main() {

    speed();

    ll n;
    cin >> n;

    vll a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    SegmentTree st(a);
    ll t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        Node m = st.getMin(0,0,n-1,l,r);
        ll g_c_d = st.getGCD(0,0,n-1,l,r);
        if(g_c_d == m.mn) {
            cout << r-l+1 -  m.t << endl;
        }
        else {
            cout << r-l+1 << endl;
        }
    }    

    return 0;
}
