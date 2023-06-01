// Find XOR of numbers from L to R

class Solution {
  public:
  
    int findBits(int n) {
        if(n%4 == 0) return n;
        if(n%4 == 1) return 1;
        if(n%4 == 2) return n+1;
        if(n%4 == 3) return 0;
    }
  
    int findXOR(int l, int r) {
        // complete the function here
        int x = findBits(l-1);
        int y = findBits(r);
        return x^y;
    }
};


// T : O(1)
// S : O(1)
