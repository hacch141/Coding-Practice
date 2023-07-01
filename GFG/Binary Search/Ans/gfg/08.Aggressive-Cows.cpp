// Aggressive Cows

class Solution {
public:

    int find_H(vector<int> &stalls, int& n) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++) {
            mini = min(mini,stalls[i]);
            maxi = max(maxi,stalls[i]);
        }
        // stalls[n-1] - stalls[0]
        return maxi-mini;
    }
    
    bool isValid(vector<int> &stalls, int n, int k, int mid) {
        int last = stalls[0];
        int cows = 1;
        
        for(int i=1; i<n; i++) {
            if(stalls[i]-last >= mid) {
                cows++;
                last = stalls[i];
            }
        }
        
        return cows >= k;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        
        int low = 1;
        int ans = -1;
        sort(stalls.begin(),stalls.end());
        int high = find_H(stalls,n);
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            if(isValid(stalls,n,k,mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

// T : O(NLogN)
// S : O(1)
