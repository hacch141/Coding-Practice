class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int cnt_1 = 0;
	    int ans_row = -1;
	    
	    for(int i=0; i<n; i++) {
	        
	        int low = 0;
	        int high = m-1;
	        
	        while(low<=high) {
	            
	            int mid = (high-low)/2 + low;
	            
	            if(arr[i][mid] == 1) {
	                high = mid-1;
	            }
	            
	            else {
	                low = mid+1;
	            }
	            
	        }
	        
	        if(m-low > cnt_1) {
	            ans_row = i;
	            cnt_1 = m-low;
	        }
	        
	    }
	    return ans_row;
	}

};
