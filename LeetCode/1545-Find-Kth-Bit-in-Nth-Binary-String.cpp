// 1545. Find Kth Bit in Nth Binary String

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--) {
            string tmp = s;
            for(auto &ch : tmp) {
                ch = ch == '0' ? '1' : '0';
            }
            reverse(tmp.begin(),tmp.end());
            s += '1';
            s += tmp;
        }
        return s[k - 1];
    }
};
