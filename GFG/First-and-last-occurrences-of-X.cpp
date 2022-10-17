//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        vector<int> ans;
        int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(first != n && arr[first] == x) {
            ans.push_back(first);
        }
        else {
            return {-1};
        }
        int last = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
        last--;
        if(last>=0 && arr[last] == x) {
            ans.push_back(last);
        }
        else {
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends
