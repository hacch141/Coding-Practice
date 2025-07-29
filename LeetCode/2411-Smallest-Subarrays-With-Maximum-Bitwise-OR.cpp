// 2411. Smallest Subarrays With Maximum Bitwise OR

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        int curr_xor = 0;
        vector<int> mx_xor(n);
        for(int i = n - 1; i >= 0; i--) {
            curr_xor |= nums[i];
            mx_xor[i] = curr_xor;
        }

        int l = 0, curr = 0;
        vector<int> bits(32, 0), ans;
        for(int r = 0; r < n; r++) {
            int num = nums[r];
            for(int i = 0; i < 32; i++) {
                if((num >> i) & 1) {
                    bits[i]++;
                    if(bits[i] == 1) curr |= (1 << i);
                }
            }
            while(l <= r && curr == mx_xor[l]) {
                ans.push_back(r - l + 1);
                int num = nums[l];
                for(int i = 0; i < 32; i++) {
                    if((num >> i) & 1) {
                        bits[i]--;
                        if(bits[i] == 0) curr -= (1 << i);
                    }
                }
                l++;
            }
        }

        return ans;
    }
};

// 
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(30, -1), ans(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if ((nums[i] >> j) & 1) {
                    last[j] = i;
                } else if (last[j] >= 0) {
                    ans[i] = max(ans[i], last[j] - i + 1);
                }
                
            }
            
        }
        return ans;
    }
};
