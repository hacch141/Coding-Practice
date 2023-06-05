class Solution {
    
  private:
    void helper(int ind, int target, vector<int> &A, vector<int>& ds, vector<vector<int> >& ans) {
        if(ind == A.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if(A[ind]<=target) {
            ds.push_back(A[ind]);
            helper(ind, target-A[ind], A, ds, ans);
            ds.pop_back();
        }
        helper(ind+1, target, A, ds, ans);
        return;
    }
    
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int> > ans;
        vector<int> ds;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        helper(0,B,A,ds,ans);
        return ans;
    }
};
