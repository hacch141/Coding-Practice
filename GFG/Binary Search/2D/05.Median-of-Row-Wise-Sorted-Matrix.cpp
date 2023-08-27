// Median of Row Wise Sorted Matrix

#include <bits/stdc++.h>

// find # of ele less than equal to ele
int bs(vector<int> &arr, int &ele) {
    int low = 0;
    int high = arr.size() - 1;

    int cnt = 0;
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(arr[mid] <= ele) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int median(vector<vector<int>> &matrix, int n, int m) {
    // Write your code here.
    int low = 0;
    int high = 1e9;

    while(low <= high) {
        int mid = (high-low)/2 + low;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += bs(matrix[i],mid);
        }
        if(cnt <= (m*n)/2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}
// T : O(n * log(m))
// S : O(1)
