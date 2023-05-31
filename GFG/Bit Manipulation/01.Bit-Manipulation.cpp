// Bit Manipulation

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int a = (num>>(i-1))&1;
        int b = num | (1<<(i-1));
        int c = num & (~(1<<(i-1)));
        cout << a << " " ;
        cout << b << " " ;
        cout << c ;
    }
};

// T : O(1)
// S : O(1)
