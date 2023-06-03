// Rat in a Maze Problem - I

class Solution{
    
    private:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string>& ans, string move, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return;
        }
        string dir = "URDL";
        for(int idx=0; idx<4; idx++) {
            int nRow = i+delRow[idx];
            int nCol = j+delCol[idx];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && !vis[nRow][nCol] && m[nRow][nCol]==1) {
                vis[i][j] = 1;
                solve(nRow,nCol,m,n,ans,move+dir[idx],vis,delRow, delCol);
                vis[i][j] = 0;
            }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        if(m[0][0]==1) {
            solve(0,0,m,n,ans,"",vis,delRow,delCol);
        }
        return ans;
    }
};

// T : O(3^(n^2))
// S : O(L * X), L = length of the path, X = number of paths.
