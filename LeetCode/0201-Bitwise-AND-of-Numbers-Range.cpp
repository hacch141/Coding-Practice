// 201. Bitwise AND of Numbers Range

class Solution {
public:

    int rangeBitwiseAnd(long long left, long long right) {
        while(right > left) {
            right = right & (right - 1);
        }
        return right;
    }
};


class Solution {
public:

    void cnt_bits(long long n, vector<int>& bits) {
        if(n <= 0) return;
        if(n == 1) {
            bits[0]++;
            return;
        }
        if(n == 2) {
            bits[0]++;
            bits[1]++;
            return;
        }
            
        int msb = log2(n);
        int cn = (1LL << msb);
        bits[msb] += (n - cn + 1);
        for(int i = 0; i < msb; i++) {
            bits[i] += (cn / 2);
        }
        cnt_bits(n - cn, bits);
    }

    int rangeBitwiseAnd(long long left, long long right) {
        vector<int> lbits(31,0), rbits(31,0), tot(31,0);
        cnt_bits(left - 1, lbits);
        cnt_bits(right, rbits);
        int ans = 0;
        for(int i = 0; i < 31; i++) {
            tot[i] = rbits[i] - lbits[i];
            if(tot[i] == right - left + 1) ans |= (1LL << i);
        }
        return ans;
    }
};
