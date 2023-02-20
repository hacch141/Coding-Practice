// 1331. Rank Transform of an Array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr);
        int n = arr.size();
        
        sort(ans.begin(),ans.end());
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++) {
            if(mp.find(ans[i]) == mp.end()) {
                mp[ans[i]] = mp.size()+1;
            }
        }

        for(int i=0; i<n; i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};
