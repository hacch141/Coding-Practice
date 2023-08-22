// Number of NGEs to the right

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.
    int n = arr.size();
    int m = query.size();

    vector<int> ans(m);

    for(int i=0; i<m; i++) {
        int cnt = 0;
        for(int j=query[i]+1; j<n; j++) {
            if(arr[j] > arr[query[i]]) {
                cnt++;
            }
        }
        ans[i] = cnt;
    }

    return ans;
}
// T : O(N*Q)
// S : O(1)
