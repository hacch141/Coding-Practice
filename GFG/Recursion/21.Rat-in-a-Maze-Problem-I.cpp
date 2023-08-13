// Rat in a Maze Problem - I

string direction = "URDL";
vector<int> delRow = {-1, 0, +1, 0};
vector<int> delCol = {0, +1, 0, -1};

void solve(int row, int col, int& n, int& m, string& curr, vector<vector<int>> &mat,
vector<string>& ans, vector<vector<int>>& vis) {
    if(row == n-1 && col == m-1) {
        ans.push_back(curr);
        return;
    }

    vis[row][col] = 1;
    for(int del=0; del<4; del++) {
        int nRow = row + delRow[del];
        int nCol = col + delCol[del];
        curr += direction[del];
        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && mat[nRow][nCol]==1) {
            solve(nRow,nCol,n,m,curr,mat,ans,vis);
        }
        curr.pop_back();
    }
    vis[row][col] = 0;
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    // Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(m,0));
    string curr = "";

    solve(0,0,n,m,curr,mat,ans,vis);
    return ans;
}

// T : O(4^(N*M)
// S : O(N*M)
