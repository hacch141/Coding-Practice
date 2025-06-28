// 2099. Find Subsequence of Length K With the Largest Sum

class Solution {
public:

    static bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
        return p1.second < p2.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.rbegin(), v.rend());
        sort(v.begin(), v.begin() + k, cmp);

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};

// ====

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> tmp = nums;
        sort(tmp.rbegin(), tmp.rend());
        multiset<int> st;
        for(int i = 0; i < k; i++) {
            st.insert(tmp[i]);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(st.count(nums[i])) {
                ans.push_back(nums[i]);
                st.erase(st.find(nums[i]));
            }
        }

        return ans;
    }
};
