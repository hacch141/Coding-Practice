// 3020. Find the Maximum Number of Elements in Subset

class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
        map<long long,int> mp;
        for(auto i : nums) mp[i]++;
        
        int ans = 1;
        if(mp[1] > 1) ans = mp[1] - (mp[1] % 2 == 0);
        
        for(auto i : mp) {
            if(i.first == 1) continue;
            int curr = 0;
            long long st = i.first;
            while(1) {
                if(mp[st] >= 2) {
                    st *= st;
                    curr += 2;
                }
                else if(mp[st] == 1) {
                    curr++;
                    break;
                }
                else {
                    curr--;
                    break;
                }
            }
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
