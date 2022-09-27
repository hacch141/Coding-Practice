// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int i=0; i<rowIndex+1; i++) {
            for(int j=i; j>=1; j--) {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
};
