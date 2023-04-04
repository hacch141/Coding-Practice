class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int low = 0;
       int high = n-1;
       
       while(low<high) {
           
           int mid = (high-low)/2 + low;
           
           if(arr[mid+1]>arr[mid]) {
               low = mid+1;
           }
           else {
               high = mid;
           }
           
       }
       return low;
    }
};
