// Power of 2

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n==0) return false;
        int zero = n & (n-1);
        
        return zero == 0 ? true : false;
    }
};

// T : O(1)
// S : O(1)


class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        if(n==0) return false;
        int cntOnes = 0;
        while(n>0) {
            if(n&1) {
                // if(cntOnes!=0) return false;
                cntOnes++;
            }
            n = n>>1;
        }
        
        return cntOnes == 1 ? true : false;
    }
};

// T : O(N)
// S : O(1)
