// 1122. Relative Sort Array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);
        for(auto i : arr1) count[i]++;
        set<int> st;
        for(auto i : arr2) st.insert(i);

        vector<int> ans;
        for(auto i : arr2) {
            for(int j = 0; j < count[i]; j++) {
                ans.push_back(i);
            }
        }
        for(int c = 0; c <= 1000; c++) {
            if(st.count(c)) continue;
            for(int j = 0; j < count[c]; j++) {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
