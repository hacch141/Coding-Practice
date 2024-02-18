// 3041. Maximize Consecutive Elements in an Array After Modification

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        map<int,int> mp, mp2;
        for(auto i : nums) mp[i]++;
        for(auto i : mp) {
            int num = i.first, f = i.second;
            if(mp2.find(num) != mp2.end()) {
                mp2[num + 1] += f;
            }
            else {
                mp2[num]++;
                if(f > 1) mp2[num + 1] += (f - 1);
            }
        }
        
        int ans = 1, c, st;
        for(auto i : mp2) {
            int num = i.first, f = i.second;
            if(mp2.find(num - 1) != mp2.end()) continue;
            
            c = 1, st = num;
            while(mp2.find(num + 1) != mp2.end()) {
                num++;
                c++;
            }
            
            while(mp.find(st - 2) != mp.end()) {
                st--;
                c++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};
