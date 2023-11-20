// 2391. Minimum Amount of Time to Collect Garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0, n = garbage.size();
        int lastM = -1, lastP = -1, lastG = -1;

        for(int i=0; i<n; i++) {
            for(auto g : garbage[i]) {
                if(g == 'M') {
                    lastM = i;
                }
                else if(g == 'P') {
                    lastP = i;
                }
                else if(g == 'G') {
                    lastG = i;
                }
            }
            ans += garbage[i].length();
        }

        int len = travel.size();
        vector<int> prefix(len,0);
        prefix[0] = travel[0];
        for(int i=1; i<len; i++) {
            prefix[i] = prefix[i-1] + travel[i];
        }

        if(lastM != -1 && lastM != 0) ans += prefix[lastM-1];
        if(lastP != -1 && lastP != 0) ans += prefix[lastP-1];
        if(lastG != -1 && lastG != 0) ans += prefix[lastG-1];

        return ans;
    }
};
