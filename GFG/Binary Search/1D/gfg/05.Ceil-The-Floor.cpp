// Ceil The Floor

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	int floor = -1;
	int ceil = -1;
	int low = 0;
	int high = n - 1;
	sort(arr,arr+n);

	while(low <= high) {
		int mid = (high-low)/2 + low;
		if(arr[mid] == x) {
			return {x,x};
		}
		else if(arr[mid] < x) {
			floor = arr[mid];
			low = mid + 1;
		}
		else {
			ceil = arr[mid];
			high = mid - 1;
		}
	}
	return {floor,ceil};
}

// T : O(LogN)
// S : O(1)
