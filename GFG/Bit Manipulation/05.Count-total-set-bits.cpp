// Count total set bits

class Solution{
    public:
  
    int findX(int n) {
        int x = 0;
        while((1<<x) <= n) {
            x++;
        }
        return x-1;
    }
    
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0 || n==1) return n;
        int x = findX(n);
        
        int before = (1<<(x-1))*x;
        int after = n - (1<<x) + 1;
        int rest = countSetBits(n - (1<<x));
        
        return before + after + rest;
    }
};

// T : O(Log N)
// S : O(1)
