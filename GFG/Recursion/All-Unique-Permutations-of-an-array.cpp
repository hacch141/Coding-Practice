class Solution {
    
  private:
    void helper(int idx, vector<int>& arr, int n, set<vector<int>>& s) {
        if(idx==n) {
            s.insert(arr);
            return;
        }
        for(int i=idx; i<n; i++) {
            swap(arr[i],arr[idx]);
            helper(idx+1,arr,n,s);
            swap(arr[i],arr[idx]);
        }
    }
    
  public:
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        set<vector<int>> s;
        vector<vector<int>> ans;
        helper(0,arr,n,s);
        for(auto it : s) {
            ans.push_back(it);
        }
        return ans;
    }
};
