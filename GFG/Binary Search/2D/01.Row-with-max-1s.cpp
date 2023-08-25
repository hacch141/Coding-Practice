// Row with max 1s

#include <bits/stdc++.h>

int bs(vector<int> &arr, int &n) {
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(arr[mid] == 1) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return low;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int max_ones = 0;
    int ans = -1;

    for(int i=n-1; i>=0; i--) {
        int cnt = m - bs(matrix[i],m);
        if(cnt >= max_ones) {
            max_ones = cnt;
            ans = i;
        }
    }

    return ans;
}
// T : O(N * Log M)
// S : O(1)
