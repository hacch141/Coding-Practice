// Largest Element in the Array

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int ans = INT_MIN;
    for(auto i : arr) {
        ans = max(ans,i);
    }
    return ans;
}

// T : O(N)
// S : O(1)
