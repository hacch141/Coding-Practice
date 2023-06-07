// 1318. Minimum Flips to Make a OR b Equal to c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a || b || c) {
            int a1 = a&1;
            int b1 = b&1;
            int c1 = c&1;
            if((a1|b1) == c1) {
                a >>= 1; 
                b >>= 1; 
                c >>= 1;
                continue;
            }
            else if((((!a1)|(b1)) == c1) || (((a1)|(!b1)) == c1)) {
                flips++;
            }
            else if(((!a1)|(!b1)) == c1) {
                flips += 2;
            }
            a >>= 1; 
            b >>= 1; 
            c >>= 1;
        }
        return flips;
    }
};
