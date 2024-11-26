// 1574. Shortest Subarray to be Removed to Make Array Sorted

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), ans = INT_MAX, l = n, r = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i - 1]) {
                l = i; break;
            }
        }
        ans = min(ans, n - l);
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1]) {
                r = i + 1; break;
            }
        }
        ans = min(ans, r);
        for(int i = 0; i < l; i++) {
            while(r < n && arr[r] < arr[i]) r++;
            if(r > i && r < n) ans = min(ans, r - i - 1);
        }
        return ans != INT_MAX ? ans : 0;
    }
}; 
