// Left rotate an array by D places

void Rotatetoright(int arr[], int n, int k) {
  if (n == 0) return;
  k = k % n;
  if (k > n) return;
  int temp[k];
  for(int i=0; i<k; i++) {
    temp[i] = arr[i];
  }
  for(int i=0; i<n-k; i++) {
    arr[i] = arr[i+k];
  }
  for (int i=n-k; i<n; i++) {
    arr[i] = temp[i-n+k];
  }
}

// T : O(N)
// S : O(K)


void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
// Function to Rotate k elements to left
void Rotateeletoleft(int arr[], int n, int k)
{
  // Reverse first k elements
  Reverse(arr,0,k-1);
  // Reverse last n-k elements
  Reverse(arr,k,n-1);
  // Reverse whole array
  Reverse(arr,0,n-1);
}
// T : O(N)
// S : O(1)
