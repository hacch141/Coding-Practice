// 1207. Unique Number of Occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> check;
        
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        for(auto i : mp) {
            check.push_back(i.second);
        }
        sort(check.begin(),check.end());
        
        int flag = 0;
        for(int i=1; i<check.size(); i++) {
            if(check[i] == check[i-1]) {
                flag = 1;
            }
        }
        if(flag) {
            return false;
        }
        return true;
    }
};
