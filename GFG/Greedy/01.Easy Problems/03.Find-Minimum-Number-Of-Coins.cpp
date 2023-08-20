// Find Minimum Number Of Coins

vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    for(int i=8; i>=0; i--) {
        while(coins[i] <= n) {
            n -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    return ans;
}
// T : O(Number of coins)
// S : O(1)
