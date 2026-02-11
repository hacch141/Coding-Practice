// Print subarray with maximum subarra

class Solution {
    public long maxSubarraySum(int[] arr, int n) {
        long maxSum = Long.MIN_VALUE;
        long sum = 0;

        int start = 0;
        int ansStart = 0, ansEnd = 0;

        for (int i = 0; i < n; i++) {
            if (sum == 0) start = i;
            sum += arr[i];

            if (sum > maxSum) {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0) sum = 0;
        }

        // Optional: print subarray
        System.out.print("Subarray: ");
        for (int i = ansStart; i <= ansEnd; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        return maxSum;
    }
}

// ============================================================

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}


int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    long long sum = 0;

    int i = 0;
    int j = 0;
    int ans = 0;

    while(j<n) {
        sum += a[j];
        while(i<j && sum>k) {
            sum -= a[i];
            i++;
        }
        if(sum == k) {
            ans = max(ans,j-i+1);
        }
        j++;
    }
    return ans;
}
// T : O(N)
// S : O(1)


/*
    Time Complexity: O( N^2 ) 
    Space Complexity: O(1)

    where N is the size of array 'A'.
*/
int longestSubarrayWithSumK(vector < int > a, long long k) {

    int n = a.size();
    // maxLength is used to store the maximum 
    // length of a subarray whose sum = 'k'
    
    int maxLength = 0;

    // Iterating over 'a'
    for (int i = 0; i < n; ++i) {
        long long currentSum = 0;
        for(int j = i; j < n; ++j) {
            currentSum += a[j];

            if(currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}
