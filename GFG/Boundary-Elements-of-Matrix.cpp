// Boundary Elements of Matrix

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&matrix){
        // Code here
        vector<int> ans;
        for (int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(i==0 || i==matrix.size()-1) {
                    ans.push_back(matrix[i][j]);
                }
                else if(j==0 || j==matrix[i].size()-1) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
