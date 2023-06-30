// Smallest Divisor

class Solution {
public:

    int find_H(vector<int>& nums) {
        int high = INT_MIN;
        for(auto i : nums) {
            high = max(high,i);
        }
        return high;
    }
    
    bool isValid(vector<int>& nums, int K, int mid) {
        int total = 0;
        for(auto i : nums) {
            total += ceil(double(i)/(double)mid);
        }
        return total <= K;
    }

    int smallestDivisor(vector<int>& nums, int K) {
        // Write your code here.
        if(K < nums.size()) return -1;
        int low = 1;
        int high = find_H(nums);
        
        int ans = high;
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            if(isValid(nums,K,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// T : O(N + N*LogN)
// S : O(1)
