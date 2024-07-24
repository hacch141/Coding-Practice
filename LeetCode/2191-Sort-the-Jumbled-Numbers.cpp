// 2191. Sort the Jumbled Numbers
class Solution {
public:

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }

    int getNum(int num, vector<int>& mapping) {
        string str = to_string(num);

        int newNum = 0;
        for(auto ch : str) {
            newNum = newNum * 10 + (mapping[ch - '0']);
        }

        return newNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int>(3));
        for(int i = 0; i < n; i++) {
            v[i][0] = getNum(nums[i], mapping);
            v[i][1] = i;
            v[i][2] = nums[i];
        }

        sort(v.begin(),v.end(), cmp);
        vector<int> ans;
        for(auto i : v) ans.push_back(i[2]);
        return ans;
    }
};
