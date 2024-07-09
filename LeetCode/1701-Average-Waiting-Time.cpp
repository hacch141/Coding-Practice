// 1701. Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), t = 0;
        vector<int> wait;
        for(int i = 0; i < n; i++) {
            int currLate = max(t, customers[i][0]) - customers[i][0];
            wait.push_back(currLate + customers[i][1]);
            t = max(t, customers[i][0]) + customers[i][1];
        }
        double ans = 0;
        for(auto i : wait) ans += i;
        return ans / n;;
    }
};
