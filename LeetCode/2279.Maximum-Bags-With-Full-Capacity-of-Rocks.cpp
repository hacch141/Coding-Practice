// 2279. Maximum Bags With Full Capacity of Rocks

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        int n = capacity.size();
        for(int i=0; i<n; i++) {
            v.push_back( capacity[i] - rocks[i] );
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int cap = 0;
        for(int i=0; i<n; i++) {
            cap += v[i];
            if(cap <= additionalRocks) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};
