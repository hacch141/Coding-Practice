// Kadane's Algorithm, maximum subarray sum

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long ans = INT_MIN;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum < 0) {
            sum = 0;
        }
        ans = max(ans,sum);
    }
    return ans;
}

// T : O(N)
// S : O(1)

/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    where N is the length of the array.
*/

#include <algorithm>

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = 0;

    for(int i=0; i<n; i++)
    {
        long long curSum = 0;

        for(int j=i; j<n; j++)
        {
            curSum += arr[j];
            maxSum = max(maxSum, curSum);
        }
    }

    return maxSum;
}
