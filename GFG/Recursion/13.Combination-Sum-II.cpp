// Combination Sum II

class Solution {
  public:
  
    void solve(int idx, int& n, int target, vector<int> &candidates, vector<int>& ds, vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<n; i++) {
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            solve(i+1,n,target-candidates[i],candidates,ds,ans);
            ds.pop_back();
        }
    }
  
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,n,target,candidates,ds,ans);
        return ans;
    }
};
// T : O(2^n + n*Log N)
// S : O(n)


// Brute Force 
#include <bits/stdc++.h>

void solve(int i, int& n, int sum, vector<int>& arr,
 vector<int>& curr, set<vector<int>>& st) {
	if(i == n) {
		if(sum == 0) {
			st.insert(curr);
		}
		return;
	}

	solve(i+1,n,sum,arr,curr,st);
	if(arr[i] <= sum) {
		curr.push_back(arr[i]);
		solve(i+1,n,sum-arr[i],arr,curr,st);
		curr.pop_back();
	}
	return;
}

vector<vector<int>> combinationSum2(vector<int> &arr,
 int n, int target){
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> curr;
	set<vector<int>> st;

	sort(arr.begin(),arr.end());
	
	solve(0,n,target,arr,curr,st);
	for(auto i : st) {
		ans.push_back(i);
	}
	return ans;
}
