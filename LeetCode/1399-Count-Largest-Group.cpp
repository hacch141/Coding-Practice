// 1399. Count Largest Group

class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> mp_sum;
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            int s = 0, num = i;
            while(num) {
                s += (num % 10);
                num /= 10;
            }
            mp_sum[s]++;
            mx = max(mx, mp_sum[s]);
        }

        int ans = 0;
        for(auto &it : mp_sum) {
            ans += it.second == mx;
        }

        return ans;
    }
};
