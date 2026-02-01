// Floyd Warshall

class Solution {
    public void shortest_distance(int[][] matrix) {
        int n = matrix.length;
        int INF = (int) 1e9;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = INF;
                }
            }
        }

        for (int v = 0; v < n; v++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][v] < INF && matrix[v][j] < INF) {
                        matrix[i][j] = Math.min(matrix[i][j], matrix[i][v] + matrix[v][j]);
                    }
                }
            }
        }

        // Step 3: Restore unreachable paths to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1;
                }
            }
        }

        // Step 4: Negative cycle check (optional, for understanding)
        for (int i = 0; i < n; i++) {
            if (matrix[i][i] < 0) {
                // Negative cycle exists
                // (GFG does not require returning anything here)
            }
        }
    }
}

// ============================================================================

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
