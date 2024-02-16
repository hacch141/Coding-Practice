// 1481. Least Number of Unique Integers after K Removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i : arr) mp[i]++;
        vector<int> v;
        for(auto i : mp) v.push_back(i.second);
        sort(v.begin(), v.end());

        int sum = 0, rem = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(sum + v[i] <= k) {
                rem++;
                sum += v[i];
            }
            else {
                break;
            }
        }

        return v.size() - rem;
    }
};
