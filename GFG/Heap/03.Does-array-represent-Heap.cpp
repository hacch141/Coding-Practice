// Does array represent Heap

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
