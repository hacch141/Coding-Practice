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
