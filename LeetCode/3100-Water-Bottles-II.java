// 3100. Water Bottles II

class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, empty = 0;
        while (numBottles > 0) {
            ans += numBottles;
            empty += numBottles;
            int newBottles = 0;
            while (empty >= numExchange) {
                empty -= numExchange;
                newBottles++;
                numExchange++;
            }
            numBottles = newBottles;
        }
        return ans;
    }
}
