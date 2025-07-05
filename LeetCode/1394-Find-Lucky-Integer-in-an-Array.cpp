// 1394. Find Lucky Integer in an Array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> f(501, 0);
        for(auto i : arr) f[i]++;
        int ans = -1;
        for(int i = 1; i <= 500; i++) {
            if(f[i] == i) ans = i;
        }
        return ans;
    }
};
