// Trapping Rainwater

#include <bits/stdc++.h>

long long getTrappedWater(long long* arr, int n) {
    // Write your code here.

    if(n <= 2) return 0;

    long long leftMax = 0;
    long long rightMax = 0;

    int low=0, high=n-1;
    long long ans = 0;

    while(low <= high) {
        if(leftMax <= rightMax) {
            if(arr[low] < leftMax) {
                ans += (leftMax - arr[low]);
            }
            else {
                leftMax = max(leftMax,arr[low]);
            }
            low++;
        }
        else {
            if(arr[high] < rightMax) {
                ans += (rightMax - arr[high]);
            }
            else {
                rightMax = max(rightMax,arr[high]);
            }
            high--;
        }
    }

    return ans;
}
// T : O(N)
// S : O(1)


#include <bits/stdc++.h>

long long getTrappedWater(long long* arr, int n) {
    // Write your code here.

    vector<long long> rightMax(n,0), leftMax(n,0);
    long long maxi1 = INT_MIN;
    long long maxi2 = INT_MIN;

    for(int i=0; i<n; i++) {
        leftMax[i] = maxi1;
        rightMax[n-1-i] = maxi2;
        maxi1 = max(maxi1,arr[i]);
        maxi2 = max(maxi2,arr[n-1-i]);
    }

    long long ans = 0;
    for(int i=1; i<n-1; i++) {
        int h = min(leftMax[i],rightMax[i]);
        if(arr[i] < h) {
            ans += (h-arr[i]);
        }
    }

    return ans;
}
// T : O(N)
// S : O(N)


/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)

    Where N is the total number of elevations.
*/

long long getTrappedWater(long long* arr, int n) {

    // Result.
    long long ans = 0ll;

    // Traversing.
    for (int i = 1; i < n - 1; i++) {
        long long maxLeftHeight = arr[i];

        for (int j = i; j >= 0; j--) {
            maxLeftHeight = max(arr[j], maxLeftHeight);
        }

        long long maxRightHeight = arr[i];

        for (int j = i; j < n; j++) {
            maxRightHeight = max(arr[j], maxRightHeight);
        }

        // Calculation.
        ans += min(maxRightHeight, maxLeftHeight) - arr[i];
    }

    return ans;
}
