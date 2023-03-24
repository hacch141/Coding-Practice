// 605. Can Place Flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int ans = 0;
        if(size==1) {
            ans = !flowerbed[0];
            return ans>=n;
        }

        if(flowerbed[0]==0 && flowerbed[1]==0) {
            flowerbed[0] = 1;
            ans++;
        }

        for(int i=1; i<size-1; i++) {
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0) {
                flowerbed[i] = 1;
                ans++;
            }
        }

        if(flowerbed[size-2]==0 && flowerbed[size-1]==0) {
            flowerbed[size-1] = 1;
            ans++;
        }
        return ans>=n;
    }
};
