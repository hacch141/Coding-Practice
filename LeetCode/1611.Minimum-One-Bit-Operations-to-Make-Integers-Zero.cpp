// 1611. Minimum One Bit Operations to Make Integers Zero

using ll = long long;
using vll = vector<ll>;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        bool flag = true;
        int ans = 0;
        for(int i=31; i>=0; i--) {
            if(n & (1<<i)) {
                ans += flag ? pow(2,i+1) - 1 : -(pow(2,i+1) - 1);
                flag = !flag;
            }
        }

        return ans;
    }
};
