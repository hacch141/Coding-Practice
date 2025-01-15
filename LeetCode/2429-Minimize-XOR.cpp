// 2429. Minimize XOR

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt_bits = 0, tmp = num2;

        while(tmp) {
            cnt_bits += (tmp & 1);
            tmp >>= 1;
        }

        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            if((num1 >> i) & 1) {
                ans |= (1 << i);
                cnt_bits--;
            }
            if(cnt_bits == 0) break;
        }

        if(cnt_bits == 0) return ans; 

        for(int i = 0; i < 32; i++) {
            if(((ans >> i) & 1) == 0) {
                ans |= (1 << i);
                cnt_bits--;
            }
            if(cnt_bits == 0) break;
        }

        return ans;
    }
};
