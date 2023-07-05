// Distance of nearest cell having 1

// BFS
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n, vector<int>(m,0));
	    
	    queue<pair<int,int>> q;
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(grid[i][j] == 1) {
	                q.push({i,j});
	            }
	        }
	    }
	    
	    vector<int> delRow = {-1, 0, +1, 0};
	    vector<int> delCol = {0, -1, 0, +1};
	    
	    int d = 1;
	    while(!q.empty()) {
	        int size = q.size();
	        for(int i=0; i<size; i++) {
	            int r = q.front().first;
	            int c = q.front().second;
	            q.pop();
	            for(int del=0; del<4; del++) {
	                int nRow = r + delRow[del];
	                int nCol = c + delCol[del];
	                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==0 && ans[nRow][nCol]==0) {
	                    ans[nRow][nCol] = d;
	                    q.push({nRow,nCol});
	                }
	            }
	        }
	        d++;
	    }
	    
	    return ans;
	}
};

// T : O(N*M)
// S : O(N*M)
