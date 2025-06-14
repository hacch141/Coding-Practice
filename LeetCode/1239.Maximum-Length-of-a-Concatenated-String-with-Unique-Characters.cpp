// 1239. Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:

    unordered_map<int, int> mp;

    int solve(int ind, int& n, vector<string>& arr, int vis) {
        if(ind >= n) return 0;
        if(mp.find(vis) != mp.end()) return mp[vis];

        int curr_vis = 0;
        bool can_take = true;
        for(auto ch : arr[ind]) {
            int shift = ch - 'a';
            if((vis & (1 << shift)) || (curr_vis & (1 << shift))) {
                can_take = false;
                break;
            }
            curr_vis |= (1 << (ch - 'a'));
        }

        int take = INT_MIN;
        if(can_take) take = __builtin_popcount(curr_vis) + solve(ind + 1, n, arr, vis | curr_vis);
        int nottake = solve(ind + 1, n, arr, vis);
        return mp[vis] = max(take, nottake);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        mp.clear();
        return solve(0, n, arr, 0);
    }
};
