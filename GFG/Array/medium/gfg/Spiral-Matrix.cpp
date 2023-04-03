class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int left = 0, right = m-1, top = 0, bottom = n-1;
        
        int cnt = 0;
        while(left<=right && top<=bottom) {
            
            // check in top row
            for(int i=left; i<=right; i++) {
                cnt++;
                if(cnt==k) {
                    return a[top][i];
                }
            }
            top++;
            
            // check in right column
            for(int i=top; i<=bottom; i++) {
                cnt++;
                if(cnt==k) {
                    return a[i][right];
                }
            }
            right--;
            
            // check in bottom row
            if(top<=bottom) {
                for(int i=right; i>=left; i--) {
                    cnt++;
                    if(cnt==k) {
                        return a[bottom][i];
                    }
                }
            }
            bottom--;
            
            // check in left column
            if(left<=right) {
                for(int i=bottom; i>=top; i--) {
                    cnt++;
                    if(cnt==k) {
                        return a[i][left];
                    }
                }
            }
            left++;
        }
        return -1;
    }

};
