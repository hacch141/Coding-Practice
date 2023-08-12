// Search in a row and column wise sorted matrix

class Solution {
public:

    bool find(vector<vector<int>>& matrix, int target, int c) {
        int low = 0;
        int high = matrix.size() - 1;

        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(matrix[mid][c] == target) {
                return true;
            }
            else if(matrix[mid][c] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int c=0; c<m; c++) {
            if(find(matrix,target,c) == true) return true;
        }

        return false;
    }
};
// T : O(m * Log n)
// S : O(1)

// Optimised
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i<n && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] < target) {
                i++;
            }
            else if(matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};

// T : O(n+m)
// S : O(1)
