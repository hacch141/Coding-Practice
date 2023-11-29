#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

class Bracket {
    public:
    ll open, close, full;

    Bracket() {
        open = 0;
        close = 0;
        full = 0;
    }
};

class Segment {
    vector<Bracket> tree;
    string str;

    public:
    Segment(string& s, int n) {
        tree.resize(4*n);
        str = s;
        BuildTree(0,0,n-1);
    }

    Bracket merge(Bracket& b1 , Bracket& b2) {
        Bracket b;
        b.open = b1.open + b2.open - min(b1.open,b2.close);
        b.close = b1.close + b2.close - min(b1.open,b2.close);
        b.full = b1.full + b2.full + 2*min(b1.open,b2.close);
        return b;
    }

    void BuildTree(ll ind, ll ss, ll se) {
        if(ss == se) {
            if(str[ss] == '(') {
                tree[ind].open = 1;
            }
            else {
                tree[ind].close = 1;
            }
            return;
        }

        ll mid = (ss+se)/2;
        BuildTree(2*ind + 1, ss, mid);
        BuildTree(2*ind + 2, mid+1, se);

        tree[ind] = merge(tree[2*ind + 1],tree[2*ind + 2]);
    }

    Bracket query(ll ind, ll ss, ll se, ll qs, ll qe) {
        
        if(se < qs || qe < ss) return Bracket();
        if(qs <= ss && se <= qe) return tree[ind];

        ll mid = (ss+se)/2;
        Bracket left = query(2*ind + 1, ss, mid, qs, qe);
        Bracket right = query(2*ind + 2, mid+1, se, qs, qe); 

        return merge(left,right);
    }
};

int main() {

    string s;
    cin >> s;
    ll n=s.length();
    Segment st(s,n);

    ll m;
    cin >> m;
    while(m--) {
        ll l ,r;
        cin >> l >> r;
        l--;
        r--;
        cout << st.query(0,0,n-1,l,r).full << endl;
    }

    return 0;
}
