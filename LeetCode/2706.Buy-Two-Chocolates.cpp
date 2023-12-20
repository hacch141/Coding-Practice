// 2706. Buy Two Chocolates

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < mn1) {
                mn2 = mn1;
                mn1 = prices[i];
            }
            else if(prices[i] < mn2) {
                mn2 = prices[i];
            }
        }
        return mn1 + mn2 <= money ? money - mn1 - mn2 : money;
    }
};
