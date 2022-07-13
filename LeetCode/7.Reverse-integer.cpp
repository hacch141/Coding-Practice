// 7. Reverse Integer

class Solution {
public:
    
    int reverse(int x) {
        long long rev = 0;
        int rem = 0;
        
        while(x != 0) {
            if(rev*10 > INT_MAX || rev*10 < INT_MIN) return 0;
            rem = x%10;
            rev = rev*10 + rem;
            x = x/10;
        }
        return rev;
    }
};
