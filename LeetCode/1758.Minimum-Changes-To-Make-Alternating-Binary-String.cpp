// 1758. Minimum Changes To Make Alternating Binary String

class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;
        for(int i=0; i<s.length(); i++) {
            if((i%2 == 0 && s[i] != '0') || (i%2 == 1 && s[i] != '1')) {
                c1++;
            }
            if((i%2 == 0 && s[i] != '1') || (i%2 == 1 && s[i] != '0')) {
                c2++;
            }
        }
        return min(c1,c2);
    }
};
