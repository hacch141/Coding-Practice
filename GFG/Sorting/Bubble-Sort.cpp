// Bubble Sort


// best case in : O(N^2)
void bubbleSort(int arr[], int n)
{
    // Your code here
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// optimized   best case in : O(N)
void bubbleSort(int arr[], int n)
{
    // Your code here
    for(int i=n-1; i>=0; i--) {
        int isSwap = 0;
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = 1;
            }
        }
        if(isSwap == 0) {
            return;
        }
    }
}
