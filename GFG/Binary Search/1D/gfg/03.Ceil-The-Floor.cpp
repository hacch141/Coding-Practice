// Ceil The Floor

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    
    int low = 0;
    int high = n-1;
    pair<int,int> p;
    
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(x == arr[mid]) {
            return {x,x};
        }
        else if(x < arr[mid]) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    
    if(high == -1) return {-1,arr[low]};
    
    if(low == n) return {arr[high],-1};
    
    return {arr[high],arr[low]};
}

// T : O(LogN)
// S : O(1)


// STRIVER
// Implement Upper Bound
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
// T : O(LogN)
// S : O(1)
