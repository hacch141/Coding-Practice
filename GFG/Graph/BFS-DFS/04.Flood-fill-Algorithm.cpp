// Flood fill Algorithm

class Solution {

    int[] delRow = {-1, 0, 1, 0};
    int[] delCol = {0, -1, 0, 1};

    private void dfs(int sr, int sc, int[][] image, int[][] ans,
                     int initColor, int newColor, int n, int m) {
        ans[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];

            if (nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m &&
                image[nRow][nCol] == initColor &&
                ans[nRow][nCol] != newColor) {

                dfs(nRow, nCol, image, ans, initColor, newColor, n, m);
            }
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int n = image.length;
        int m = image[0].length;

        int initColor = image[sr][sc];
        int[][] ans = new int[n][m];

        // copy image to ans
        for (int i = 0; i < n; i++) {
            System.arraycopy(image[i], 0, ans[i], 0, m);
        }

        // Optional optimization:
        if (initColor == newColor) return ans;

        dfs(sr, sc, image, ans, initColor, newColor, n, m);

        return ans;
    }
}

// =================================================================

// BFS
class Solution {
public:

    void bfs(int& sr, int& sc, vector<vector<int>>& image, vector<vector<int>>& ans, int& initColor, int& newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        ans[sr][sc] = newColor;
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==initColor && ans[nRow][nCol]!=newColor) {
                    ans[nRow][nCol] = newColor;
                    q.push({nRow,nCol});
                }
            }
            
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        bfs(sr,sc,image,ans,initColor,newColor);
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)


// DFS
class Solution {
public:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, -1, 0, +1};
    
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int& initColor, int& newColor, int& n, int& m) {
        ans[sr][sc] = newColor;
        for(int i=0; i<4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==initColor && ans[nRow][nCol]!=newColor) {
                dfs(nRow,nCol,image,ans,initColor,newColor,n,m);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        dfs(sr,sc,image,ans,initColor,newColor,n,m);
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
