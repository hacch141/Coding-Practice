// 835. Image Overlap

class Solution {
public:
    
    int helper(vector<vector<int>>& img1, vector<vector<int>>& img2, int rOff, int cOff) {
        int n = img1[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i+rOff<0 || i+rOff>=n || j+cOff<0 || j+cOff>=n) {
                    continue;
                }
                if(img1[i][j]+img2[i+rOff][j+cOff] == 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1[0].size();
        for(int i=-n+1; i<n; i++) {
            for(int j=-n+1; j<n; j++) {
                ans = max(ans,helper(img1,img2,i,j));
            }
        }
        return ans;
    }
};
