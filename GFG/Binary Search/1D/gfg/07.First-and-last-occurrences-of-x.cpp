vector<int> find(int arr[], int n , int x ) {
    // code here
    int first, last;
    
    int low = 0;
    int high = n-1;
    bool flag = false;
    
    // binary search for first occurance
    while(low<=high) {
        int mid = (high-low)/2 +low;
        if(arr[mid]==x) flag = true;
        if(arr[mid] >= x) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    first = low;
    
    
    low = 0;
    high = n-1;
    
    // binary search for last occurance
    while(low<=high) {
        int mid = (high-low)/2 +low;
        if(arr[mid] <= x) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    last = high;
    
    if(!flag) return {-1,-1};
    return {first,last};
}
