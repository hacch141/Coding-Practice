// Convert Min Heap To Max Heap

class Solution {

    public void convertMinToMaxHeap(int[] arr) {

        int n = arr.length;

        // Start from last non-leaf node
        for (int i = (n / 2) - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    }

    private void maxHeapify(int[] arr, int n, int i) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check right child
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If root is not largest
        if (largest != i) {
            swap(arr, i, largest);
            maxHeapify(arr, n, largest);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// ====================================================================

void heapify(vector<int>& arr, int& n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && arr[largest] < arr[left]) {
		largest = left;
	}

	if(right < n && arr[largest] < arr[right]) {
		largest = right;
	}

	if(largest != i) {
		swap(arr[largest] , arr[i]);
		heapify(arr, n, largest);
	}
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	for(int i=n/2-1; i>=0; i--) {
		heapify(arr,n,i);
	}
	return arr;
}
// T : O(N LogN)
// S : O(1)
