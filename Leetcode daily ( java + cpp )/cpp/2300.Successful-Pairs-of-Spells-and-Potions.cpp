// 2300. Successful Pairs of Spells and Potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++) {
            int low = 0;
            int high = m-1;
            while(low<=high) {
                int mid = (high-low)/2 + low;
                if((long long)spells[i]*potions[mid] >= success) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            ans.push_back(m-1-low+1);
        }
        return ans;
    }
};
