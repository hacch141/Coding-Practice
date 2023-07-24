// Longest Subarray With Sum K

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    int i=0, j=0;
    int ans = 0;
    long long sum = 0;

    while(j<n) {
        sum += a[j];
        while(i<j && sum >k) {
            sum -= a[i];
            i++;
        }
        if(sum == k) {
            ans = max(ans, j-i+1);
        }
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(1)
