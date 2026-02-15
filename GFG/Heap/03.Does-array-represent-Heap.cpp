// Does array represent Heap

class Solution {

    public boolean isMaxHeap(int[] arr) {

        int n = arr.length;

        // Only need to check non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++) {

            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            // Check left child
            if (leftChild < n && arr[i] < arr[leftChild]) {
                return false;
            }

            // Check right child
            if (rightChild < n && arr[i] < arr[rightChild]) {
                return false;
            }
        }

        return true;
    }
}

// ======================================================================

class Solution{
    public:
    
    bool solve(int i , int a[], int& n) {
        if(i>n) return true;
        
        int lc = 2*i + 1;
        int rc = 2*i + 2;
        
        if((lc<n && a[i] <= a[lc]) || (rc < n && a[i] <= a[rc])) {
            return false;
        }
        
        bool l = solve(lc , a , n);
        bool r = solve(rc , a , n);
        
        return l && r;
    }
    
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        return solve(0,a,n);
    }
};
// T : O(N)
// S : O(1)
