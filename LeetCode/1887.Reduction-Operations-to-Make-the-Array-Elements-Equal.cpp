// 1887. Reduction Operations to Make the Array Elements Equal


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int size = 50000, mini=INT_MAX, maxi=INT_MIN;
        vector<int> freq(size+1,0);

        for(auto i : nums) {
            freq[i]++;
            mini = min(mini,i);
            maxi = max(maxi,i);
        }

        int ans = 0, cnt = 0;
        for(int i=mini+1; i <= maxi; i++) {
            if(freq[i] != 0) {
                cnt++;
                ans += (freq[i] * cnt);
            }
        }

        return ans;
    }
};

// ========================================================================


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int size = 50000;
        vector<int> freq(size+1,0);
        
        for(auto i : nums) {
            freq[i]++;
        }

        int ans = 0;
        for(int i=size-1; i>=0; i--) {
            if(freq[i] != 0) ans += freq[i+1];
            freq[i] += freq[i+1];
        }

        return ans;
    }
};
