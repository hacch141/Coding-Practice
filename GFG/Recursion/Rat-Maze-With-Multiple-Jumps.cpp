// Rat Maze With Multiple Jumps

class Solution {
public:

    bool isValid(int i, int j, int& n) {
        if(i<0 || j<0 || i>=n || j>=n) return false;
        return true;
    }

    bool solve(int i, int j, int& n, vector<vector<int>>&matrix, vector<vector<int>>& ans) {
        if(i==n-1 && j==n-1) {
            ans[i][j] = 1;
            return true;
        }
        if(!isValid(i,j,n)) return false;
        
        ans[i][j] = 1;
        for(int jump=1; jump<=matrix[i][j]; jump++) {
            if(solve(i,j+jump,n,matrix,ans)) {
                return true;
            }
            if(solve(i+jump,j,n,matrix,ans)) {
                return true;
            }
        }
        ans[i][j] = 0;
        return false;
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   vector<vector<int>> ans (n, vector<int>(n,0));
	   if(!solve(0,0,n,matrix,ans)) {
	       return {{-1}};
	   }
	   return ans;
	}

};

// T : O(n*n*k) where k is max(matrix[i][j])
// S : O(1)
