// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for(int i = 0; i < n - 1; i++) {
            map<int,int> mp;
            int xr = 0;
            for(int j = i + 1; j < n; j++) {
                xr ^= arr[j];
                mp[xr]++;
            }
            xr = 0;
            for(int j = i; j >= 0; j--) {
                xr ^= arr[j];
                ans += mp[xr];
            }
        }
        return ans;
    }
};
