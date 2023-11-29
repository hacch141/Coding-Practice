// 307. Range Sum Query - Mutable

using ll = long long;
using vll = vector<ll>;


class NumArray {
public:
    vector<int> tree, arr;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n, 0);
        arr = nums;
        BuildTree(0,0,n-1);
    }

    void BuildTree(ll ind, ll ss, ll se) {
        if(ss == se) {
            tree[ind] = arr[ss];
            return;
        }

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        BuildTree(lc,ss,mid);
        BuildTree(rc,mid+1,se);

        tree[ind] = tree[lc] + tree[rc];
        return;
    }

    void Update(ll ind, ll ss, ll se, ll i, ll val) {
        if(ss == se) {
            tree[ind] = val;
            arr[ss] = val;
            return;
        }

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        if(i <= mid) Update(lc, ss, mid, i, val);
        else Update(rc, mid+1, se, i, val);

        tree[ind] = tree[lc] + tree[rc];
        return;
    }

    ll getSum(ll ind, ll ss, ll se, ll qs, ll qe) {
        if(se < qs || qe < ss) return 0;

        if(qs <= ss && se <= qe) return tree[ind];

        ll mid = (ss+se) >> 1, lc = (ind<<1) + 1, rc = (ind<<1) + 2;
        return getSum(lc, ss, mid, qs, qe) + getSum(rc, mid+1, se, qs, qe);
    }
    
    void update(int index, int val) {
        Update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return (int)getSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
