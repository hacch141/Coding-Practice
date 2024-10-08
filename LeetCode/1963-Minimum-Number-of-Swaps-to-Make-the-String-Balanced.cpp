// 1963. Minimum Number of Swaps to Make the String Balanced

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(auto ch : s) {
            if(ch == '[') {
                cnt++;
            }
            else if(cnt > 0) {
                cnt--;
            }
        }
        return (cnt + 1) / 2;
    }
};
