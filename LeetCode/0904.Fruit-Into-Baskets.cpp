// 904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, ans=0, n=fruits.size();
        unordered_map<int,int> mp;

        for(r=0; r<n; r++) {
            mp[fruits[r]]++;
            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
