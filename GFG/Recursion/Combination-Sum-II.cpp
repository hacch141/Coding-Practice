class Solution{
    
private:
    void helper(int idx, int target, vector<int> arr, int n, vector<int>& ds, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i=idx; i<n; i++) {
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            helper(i+1,target-arr[i],arr,n,ds,ans);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,k,arr,n,ds,ans);
        return ans;
    }
};
