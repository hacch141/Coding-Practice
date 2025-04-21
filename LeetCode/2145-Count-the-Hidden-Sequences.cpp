// 2145. Count the Hidden Sequences

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        vector<long long> hidden(n + 1);
        hidden[0] = 0;
        long long mx = 0, mn = 0;

        for(int i = 0; i < n; i++) {
            hidden[i + 1] = differences[i] + hidden[i];
            mx = max(mx, hidden[i + 1]);
            mn = min(mn, hidden[i + 1]);
        }

        if(mx - mn > upper - lower) return 0;
        return (upper - lower) - (mx - mn) + 1;
    }
};
