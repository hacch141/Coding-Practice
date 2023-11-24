// 1561. Maximum Number of Coins You Can Get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());

        int mxCoins = 0, n = piles.size(), picks = n/3, ptr = n-2;
        while(picks > 0) {
            mxCoins += piles[ptr];
            ptr -= 2;
            picks--;
        }

        return mxCoins;
    }
};
