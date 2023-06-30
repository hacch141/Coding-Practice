// Search in a Rotated Array

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int low = l;
        int high = h;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(A[mid] == key) {
                return mid;
            }
            else if(A[low] <= A[mid]) {
                if(A[low] <= key && key < A[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(A[mid] < key && key <= A[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// T : O(LogN)
// S : O(1)
