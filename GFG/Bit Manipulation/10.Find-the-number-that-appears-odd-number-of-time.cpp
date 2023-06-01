// Exceptionally odd

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans ^= arr[i];
        }
        
        return ans;
    }
};

// T : O(N)
// S : O(1)
