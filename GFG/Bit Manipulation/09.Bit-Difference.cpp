// Bit Difference


class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int cnt = 0;
        int num = a^b;
        while(num) {
            num = num&(num-1);
            cnt++;
        }
        return cnt;
    }
};


class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int cnt = 0;
        while(a || b) {
            if((a&1) != (b&1)) cnt++;
            a >>= 1;
            b >>= 1;
        }
        return cnt;
    }
};

// T : O(Log N)
// S : O(1)
