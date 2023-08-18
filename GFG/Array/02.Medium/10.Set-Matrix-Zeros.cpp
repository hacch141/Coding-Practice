// Set Matrix Zeros

#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	vector<int> rows(n,0);
	vector<int> cols(m,0);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j] == 0) {
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}

	vector<vector<int>> ans = matrix;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(rows[i] || cols[j]) {
				ans[i][j] = 0;
			}
		}
	}

	return ans;
}
// T : O(N^2)
// S : O(N)



#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int row=0, col=0;

	for(int j=0; j<m; j++) {
		if(matrix[0][j] == 0) {
			row = 1;
		}
	}

	for(int i=0; i<n; i++) {
		if(matrix[i][0] == 0) {
			col = 1;
		}
	}

	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			if(matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if(row) {
		for(int j=0; j<m; j++) {
			matrix[0][j] = 0;
		}
	}

	if(col) {
		for(int i=0; i<n; i++) {
			matrix[i][0] = 0;
		}
	}

	return matrix;
}
// T : O(M*N)
// S : O(1)



void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
// T : O((N*M)*(N + M))
// S : O(1)
