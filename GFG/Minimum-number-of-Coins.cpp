class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        for(int i=9; i>=0; i--) {
            while(coins[i] <= N) {
                ans.push_back(coins[i]);
                N -= coins[i];
            }
            if(N==0) return ans;
        }
        return {};
    }
};
