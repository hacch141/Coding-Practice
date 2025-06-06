// Floyd Warshall

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	        }
	    }
	    
	    for(int v=0; v<n; v++) {
	        for(int i=0; i<n; i++) {
    	            for(int j=0; j<n; j++) {
    	                matrix[i][j] = min(matrix[i][j], matrix[i][v] + matrix[v][j]);
    	            }
    	        }
	    }
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }

	    for(int i=0; i<n; i++) {
	        if(matrix[i][i] < 0) {//then there is a neg cycle}
	    }
	}
};

// T : O(V^3)
// S : O(V^2)
