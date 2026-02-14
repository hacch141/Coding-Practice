// Jump Game II

class Solution {
    public int jump(int[] nums) {

        int left = 0;
        int right = 0;
        int jumps = 0;

        while (right < nums.length - 1) {

            int farthest = 0;

            for (int i = left; i <= right; i++) {
                farthest = Math.max(farthest, i + nums[i]);
            }

            jumps++;
            left = right + 1;
            right = farthest;
        }

        return jumps;
    }
}

// ===================================================================

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0, ans=0;

        while(right < nums.size()-1) {
            int far = 0;
            for(int i=left; i<=right; i++) {
                far = max(far , i + nums[i]);
            }
            ans++;
            left = right+1;
            right = far;
        }

        return ans;
    }
};

// T : O(N)
// S : O(1)
