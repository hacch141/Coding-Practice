class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int low = 0;
        int high = N-1;
        
        while(low <= high) {
            
            int mid = (high-low)/2 + low;
            
            if(k == Arr[mid]) {
                return mid;
            }
            
            else if(k > Arr[mid]) {
                low = mid+1;
            }
            
            else {
                high = mid-1;
            }
        }
        return low;
    }
};
