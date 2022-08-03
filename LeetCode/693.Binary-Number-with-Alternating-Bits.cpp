// 693. Binary Number with Alternating Bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n%2;
        int curr;
            while(n>0){
                n/=2;
                curr = n%2;
                if(curr==prev){
                    return false;
                }
                prev = curr;
            }
        return true;   
    }
};
