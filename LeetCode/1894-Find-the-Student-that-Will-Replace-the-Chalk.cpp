// 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto i : chalk) sum += i;
        k %= sum;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return -1;
    }
};
