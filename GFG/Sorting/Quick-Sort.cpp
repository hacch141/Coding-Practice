// Quick Sort

int partition (int arr[], int low, int high)
{
   // Your code here
   int i = low;
   int j = high;
   int pivot = arr[low];
   while(i<j) {
       while(arr[i] <= pivot && i<=high-1) {
           i++;
       }
       while(arr[j] > pivot && j>=low+1) {
           j--;
       }
       if(i<j) {
           int temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
       }
   }
   int temp = arr[low];
   arr[low] = arr[j];
   arr[j] = temp;
   return j;
}

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high) {
        int part = partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
    }
}
