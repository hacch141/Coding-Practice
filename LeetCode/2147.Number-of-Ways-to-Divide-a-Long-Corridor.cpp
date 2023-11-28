// 2147. Number of Ways to Divide a Long Corridor

class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1, mod = 1e9 + 7;
        int n = corridor.length(), i = 0, cnt = 0;
        bool flag = true;

        while(i < n) {
            while(i < n && cnt != 2) {
                if(corridor[i] == 'S') {
                    cnt++;
                    flag = false;
                }
                i++;
            }

            long long plants = 1;
            while(i < n && corridor[i] == 'P') {
                plants++;
                i++;
            }

            if(i < n && corridor[i] == 'S') {
                ans = (ans*plants) % mod;
            }
            else {
                break;
            }

            cnt = 0;
        }

        if(cnt == 1 || flag) return 0;
        return ans;
    }
};
