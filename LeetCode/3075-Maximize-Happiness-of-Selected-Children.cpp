// 3075. Maximize Happiness of Selected Children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int n = happiness.size(), mins = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            if(happiness[i] - mins <= 0) break;
            ans += happiness[i] - mins;
            mins++;
        }
        return ans;
    }
};
