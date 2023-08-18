// Rotate Matrix by 90 degrees

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n = mat.size();

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			swap(mat[i][j],mat[j][i]);
		}
	}

	for(int i=0; i<n; i++) {
		int low = 0;
		int high = n-1;
		while(low < high) {
			swap(mat[i][low],mat[i][high]);
			low++;
			high--;
		}
	}
}
// T : O(M*N)
// S : O(1)

#include<vector>

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n = mat.size();

	vector<vector<int>> ans(n, vector<int>(n,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans[i][j] = mat[n-1-j][i];
		}
	}

	mat = ans;
}
// T : O(M*N)
// S : O(M*N)
