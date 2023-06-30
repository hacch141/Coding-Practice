// Koko Eating Bananas

class Solution {
  public:
  
    int find_max(vector<int>& piles, int& N) {
        int maxi = INT_MIN;
        for(int i=0; i<N; i++) {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    
    bool isValid(vector<int>& piles, int& N, int& H, int mid) {
        int time = 0;
        for(int i=0; i<N; i++) {
            time += ceil((double)piles[i]/(double)mid);
        }
        return time <= H;
    }
  
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int low = 1;
        int high = find_max(piles,N); 
        int ans = high;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            if(isValid(piles,N,H,mid)) {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// T : O(N + LogN)
// S : O(1)
