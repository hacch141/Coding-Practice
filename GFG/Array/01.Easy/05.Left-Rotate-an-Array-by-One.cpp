// Left Rotate an Array by One

vector <int> rotateArray(vector<int>& arr, int n) {
    int firstElement = arr[0];
    for (int  =0; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = firstElement;
    return arr;
}

// T : O(N)
// S : O(1)
