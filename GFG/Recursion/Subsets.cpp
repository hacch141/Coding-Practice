class Solution
{
    private:
    void helper(int idx,vector<int>& A, vector<int>& ds, vector<vector<int> >& ans) {
        if(idx==A.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(A[idx]);
        helper(idx+1,A,ds,ans);
        ds.pop_back();
        helper(idx+1,A,ds,ans);
        return;
    }
    
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int> > ans;
        vector<int> ds;
        helper(0,A,ds,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
