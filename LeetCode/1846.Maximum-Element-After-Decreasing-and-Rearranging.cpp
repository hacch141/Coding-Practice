// 1846. Maximum Element After Decreasing and Rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();

        int prev = 0;
        for(int i=0; i<n; i++) {
            arr[i] = min(arr[i],prev+1);
            prev = arr[i];
        }

        return arr[n-1];
    }
};
