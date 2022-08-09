// Longest Span in two Binary Arrays

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        // code here 
        int arr[n];
        int a, b;
        for(int i=0; i<n; i++) {
            a = arr1[i]==true ? 1 : 0;
            b = arr2[i]==true ? 1 : 0;
            arr[i] = a-b;
        }
            
        unordered_map<int,int> mp;
        int pre_fix = 0;
        int ans = 0;
            
        for(int i=0; i<n; i++) {
            pre_fix += arr[i];
            if(pre_fix == 0) {
                ans = max(ans,i+1);
            }
            if(mp.find(pre_fix) == mp.end()) {
                mp[pre_fix] = i;
            }
            if(mp.find(pre_fix) != mp.end()) {
                ans = max(ans,i-mp[pre_fix]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
