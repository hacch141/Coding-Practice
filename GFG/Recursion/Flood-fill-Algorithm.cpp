// Flood fill Algorithm

class Solution {
public:

    void solve(int i, int j, int& n, int& m, vector<vector<int>>& image, vector<vector<int>>& ans, int& initial_color, int& newColor) {
        
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=initial_color || ans[i][j]==newColor) return;
        
        ans[i][j] = newColor;
        solve(i-1,j,n,m,image,ans,initial_color,newColor);
        solve(i,j-1,n,m,image,ans,initial_color,newColor);
        solve(i+1,j,n,m,image,ans,initial_color,newColor);
        solve(i,j+1,n,m,image,ans,initial_color,newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initial_color = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        solve(sr,sc,n,m,image,ans,initial_color,newColor);
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
