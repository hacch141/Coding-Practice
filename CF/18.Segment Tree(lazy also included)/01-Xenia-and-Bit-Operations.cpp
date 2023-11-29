#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

class Segment {
    vll tree, arr;
    public:
    Segment(vll a, ll n, ll N) {
        arr = a;
        tree.resize(4*n, 0);
        if(N%2 == 0) {
            BuildTree(0,0,n-1,0);
        }
        else {
            BuildTree(0,0,n-1,1);
        }
    }

    void BuildTree(ll ind, ll ss, ll se, bool _or) {
        if(ss == se) {
            tree[ind] = arr[ss];
            return;
        }

        ll mid = (ss+se)/2;
        BuildTree(2*ind + 1, ss, mid, !_or);
        BuildTree(2*ind + 2, mid+1, se, !_or);

        if(_or) tree[ind] = (tree[2*ind + 1] | tree[2*ind + 2]);
        else tree[ind] = (tree[2*ind + 1] ^ tree[2*ind + 2]);
        return;
    }

    void Update(ll ind, ll ss, ll se, bool _or, ll i, ll val) {
        if(ss == se) {
            tree[ind] = val;
            return;
        }

        ll mid = (ss+se)/2;
        if(i <= mid) Update(2*ind + 1, ss, mid, !_or, i, val);
        else Update(2*ind + 2, mid+1, se, !_or, i, val);

        if(_or) tree[ind] = (tree[2*ind + 1] | tree[2*ind + 2]);
        else tree[ind] = (tree[2*ind + 1] ^ tree[2*ind + 2]);
        
        return;
    }

    ll get_v() {
        return tree[0];
    }
};

int main() {

    ll N, n, m;
    cin >> N >> m;
    n = (1<<N);

    vll a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    bool _or = N%2;
    Segment st(a,n,N);

    while(m--) {
        ll p,b;
        cin >> p >> b;
        p--;
        st.Update(0,0,n-1,_or,p,b);
        cout << st.get_v() << endl;
    }

    return 0;
}
