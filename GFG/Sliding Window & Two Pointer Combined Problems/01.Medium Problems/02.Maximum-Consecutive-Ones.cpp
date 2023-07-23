// Maximum Consecutive Ones

#include <bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0, j=0;
    int cnt0 = 0;
    int ans = INT_MIN;

    while(j<n) {
        if(arr[j] == 0) cnt0++;
        while(i<j && cnt0>k) {
            if(arr[i] == 0) cnt0--;
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(1)
