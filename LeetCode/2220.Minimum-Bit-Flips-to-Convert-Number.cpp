// 2220. Minimum Bit Flips to Convert Number

class Solution {
public:
    int minBitFlips(int start, int goal) {
       int count = 0;
        int res = start^goal;
        while(res>0){
           count++;
            res = res & (res-1);
        }
        return count;
    }
};
