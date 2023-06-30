class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int low = 0;
        int high = N-1;
        int ind = N;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(Arr[mid] >= k) {
                ind = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ind;
    }
};

// T : O(LogN)
// S : O(1)
