// 338. Counting Bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        int i = 0;
        while(i<=n) {
            int count = 0;
            int num = i;
            while(num>0) {
                count++;
                num = num & (num-1);
            }
            res[i] = count;
            i++;
        }
        return res;
    }
};
