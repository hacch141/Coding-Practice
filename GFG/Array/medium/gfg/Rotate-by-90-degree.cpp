class Solution
{   
    public:
    
    void transpose(vector<vector<int> >& matrix, int n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void reverseRows(vector<vector<int> >& matrix, int n) {
        for(int j=0; j<n; j++) {
            for(int i=0; i<n/2; i++) {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
    
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        transpose(matrix,n);
        reverseRows(matrix,n);
    } 
};
