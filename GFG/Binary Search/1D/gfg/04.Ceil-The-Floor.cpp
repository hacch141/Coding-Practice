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
