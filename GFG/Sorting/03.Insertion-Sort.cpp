// Insertion Sort

class Solution {
    public void insertionSort(int[] arr, int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

// ==============================================================

void insertionSort(int arr[], int n)
{
    //code here
    for(int i=0; i<n; i++) {
        int j=i;
        while(j>0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}


// Recursive
void helper(int arr[], int i, int n) {
    if(i==n) return;
    int j = i;
    while(j>0 && arr[j-1] > arr[j]) {
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
    helper(arr,i+1,n);
}
    
    //Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n)
{
    //code here
    helper(arr,1,n);
}
