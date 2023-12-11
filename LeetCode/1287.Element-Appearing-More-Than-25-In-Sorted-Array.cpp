// 1287. Element Appearing More Than 25% In Sorted Array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans = 0, cnt = 1, freq = 0, prev = arr[0];

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == prev) {
                cnt++;
            }
            else {
                if(cnt > freq) {
                    ans = prev;
                    freq = cnt;
                }
                cnt = 1;
                prev = arr[i];
            }
        }
        if(cnt > freq) {
            ans = prev;
        }
        return ans;
    }
};
