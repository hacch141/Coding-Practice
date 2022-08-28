// 1329. Sort the Matrix Diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++) {
            vector<int> v;
            int j = i;
            int k = 0;
            while(j<m && k<n) {
                v.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(v.begin(),v.end());
            j = i;
            k = 0;
            int l = 0;
            while(j<m && k<n) {
                mat[j][k] = v[l];
                j++;
                k++;
                l++;
            }
        }
        
        for(int i=1; i<n; i++) {
            vector<int> v;
            int j = 0;
            int k = i;
            while(j<m && k<n) {
                v.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(v.begin(),v.end());
            j = 0;
            k = i;
            int l = 0;
            while(j<m && k<n) {
                mat[j][k] = v[l];
                j++;
                k++;
                l++;
            }
        }
        return mat;
    }
};
