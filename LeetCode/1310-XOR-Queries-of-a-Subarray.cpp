// 1310. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] ^ arr[i];
        }
        vector<int> ans;
        for(auto it : queries) {
            int curr = pref[it[1]];
            if(it[0] > 0) curr ^= pref[it[0] - 1];
            ans.push_back(curr);
        }
        return ans;
    }
};
