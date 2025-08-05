// 3477. Fruits Into Baskets II

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = 0;
        for(auto f : fruits) {
            bool get_basket = false;
            for(int i = 0; i < n; i++) {
                if(baskets[i] >= f) {
                    baskets[i] = 0;
                    get_basket = true;
                    break;
                }
            }
            if(!get_basket) ans++;
        }
        return ans;
    }
};
