// K-th missing element

int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int low = 0;
    int high = n - 1;
    
    while(low <= high) {
        int mid = low + (high-low)/2;
        
        if(a[mid]-mid-a[0] >= k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    // a[high] + more
    // a[high] + k - missingtill
    // a[high] + k - (a[high] - high - 1)
    // k + high + 1
    // k + low
    
    int ans = k + low + a[0] - 1;
    return low != n ? ans : -1;
}

// T : O(LogN)
// S : O(1)
