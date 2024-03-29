// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        long long ans = 0;
        int n = height.size();
        int lmax = 0;
        int rmax = 0;
        int left = 0;
        int right = n-1;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= lmax) lmax = height[left];
                else ans += (lmax - height[left]);
                left++;
            }
            else {
                if(height[right] >= rmax) rmax = height[right];
                else ans += (rmax - height[right]);
                right--;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         long long ans = 0;
//         int n = height.size();
//         int lmax[n];
//         int rmax[n];
        
//         lmax[0] = height[0];
//         for(int i=1; i<n; i++) {
//             lmax[i] = max(lmax[i-1],height[i]);
//         }
        
//         rmax[n-1] = height[n-1];
//         for(int i=n-2; i>=0; i--) {
//             rmax[i] = max(rmax[i+1],height[i]);
//         }
        
//         for(int i=1; i<n-1; i++) {
//             ans += min(lmax[i],rmax[i])-height[i];
//         }
//         return ans;
//     }
// };
