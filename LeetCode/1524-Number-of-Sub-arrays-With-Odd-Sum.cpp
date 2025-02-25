// 1524. Number of Sub-arrays With Odd Sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt = 0, odd_cnt = 0, even_cnt = 0, n = arr.size(), MOD = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            if(arr[i] & 1) {
                swap(odd_cnt, even_cnt);
                odd_cnt++;
            }
            else {
                even_cnt++;
            }
            cnt += odd_cnt;
            cnt %= MOD;
        }
        return cnt;
    }
};
