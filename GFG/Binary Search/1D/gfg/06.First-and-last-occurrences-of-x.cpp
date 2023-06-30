// First and last occurrences of x

int find_first(int arr[], int n , int x) {
    int low = 0;
    int high = n -1;
    int first = -1;
    
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(arr[mid] == x) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return first;
}

int find_last(int arr[], int n , int x) {
    int low = 0;
    int high = n -1;
    int last = -1;
    
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(arr[mid] == x) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

vector<int> find(int arr[], int n , int x ) {
    // code here
    int first = find_first(arr,n,x);
    int last = find_last(arr,n,x);
    return {first,last};
}

// T : O(LogN)
// S : O(1)
