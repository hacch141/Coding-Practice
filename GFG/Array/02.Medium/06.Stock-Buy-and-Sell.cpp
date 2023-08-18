// Stock Buy and Sell

int bestTimeToBuyAndSellStock(vector<int>&prices) {

    int n = prices.size();
    int maxProfit = 0, minCost = prices[0];

    // Linearly traverse the stock 'prices' array.
    for (int i = 1; i < n; i++) {
        maxProfit = max(maxProfit, prices[i] - minCost);
        minCost = min(minCost, prices[i]);
    }

    // Return 'maxProfit' here.
    return maxProfit;
}

// T : O(N)
// S : O(1)

/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the length of the array 'prices'.
*/

int bestTimeToBuyAndSellStock(vector<int>&prices) {

    int n = prices.size();

    // Initialize ‘maxProfit’ with 0.
    int maxProfit = 0;


    // Use two nested loops.The outer one will consider
    // the day the stock will be purchased and
    // the inner one will consider the days on which
    // the stock will be sold.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            // Change the value of the ‘maxProfit’ if the yield obtained
            // is greater than the ‘maxProfit’.
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }
    }

    // Return 'maxProfit' here.
    return maxProfit;
}

