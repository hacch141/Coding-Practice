// Combination Sum - III

void solve(int idx, int sum, int len, vector<int>& ds, vector<vector<int>>& ans) {
    if(len == 0) {
        if(sum == 0) {
            ans.push_back(ds);
        }
        return;
    }

    for(int i=idx; i<=9; i++) {
        if(i <= sum) {
            ds.push_back(i);
            solve(i+1,sum-i,len-1,ds,ans);
            ds.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    // Write Your Code Here
    vector<vector<int>> ans;
    vector<int> ds;
    solve(1,n,k,ds,ans);
    return ans;
}

// T : O(2^9)
// S : O(k)
