// 944. Delete Columns to Make Sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        int ans = 0;
        for(int col=0; col<len; col++) {
            for(int row=0; row<n-1; row++) {
                if(strs[row][col] > strs[row+1][col]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
