//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
    public:
    
    bool helper(vector<int> &v, int n, int k, int dist) {
        int cnt = 1;
        int coord = v[0];
        for(int i=1; i<n; i++) {
            if(v[i]-coord >= dist) {
                cnt++;
                coord = v[i];
            }
            if(cnt == k) {
                return true;
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &v) {
    
        // Write your code here
        sort(v.begin(),v.end());
        int low = 1;
        int high = v[n-1]-v[0];
        while(low <= high) {
            int mid = (low+high)/2;
            if(helper(v, n, k, mid)) {
                low = mid+1;

            }
            else {
                high = mid-1;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, vec) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
