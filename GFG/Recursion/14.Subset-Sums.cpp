// Subset Sums

class Solution
{
public:

    void solve(int idx, int& n, int sum, vector<int>& arr, vector<int>& ans) {
        if(idx==n) {
            ans.push_back(sum);
            return;
        }
        solve(idx+1,n,sum+arr[idx],arr,ans);
        solve(idx+1,n,sum,arr,ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        vector<int> ans;
        solve(0,N,0,arr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(2^N)
// S : O(2^N)
