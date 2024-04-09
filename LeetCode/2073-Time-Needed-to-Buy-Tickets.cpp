// 2073. Time Needed to Buy Tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), ans = 0;
        for(int i = 0; i <= k; i++) {
            ans += min(tickets[k], tickets[i]);
        }
        for(int i = k + 1; i < n; i++) {
            ans += min(tickets[k] - 1, tickets[i]);
        }
        return ans;
    }
};
