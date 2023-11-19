// 1887. Reduction Operations to Make the Array Elements Equal

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
