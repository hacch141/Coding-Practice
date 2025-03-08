// 2379. Minimum Recolors to Get K Consecutive Black Blocks

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int non_black = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                non_black -= blocks[i - k] != 'B';
            }
            non_black += blocks[i] != 'B';
            if(i >= k -1) ans = min(ans, non_black);
        }
        return ans;
    }
};
