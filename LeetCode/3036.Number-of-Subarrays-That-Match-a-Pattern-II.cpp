// 3036. Number of Subarrays That Match a Pattern II

class Solution {
public:
    
    vector<int> kmp(string& s) {
        int n = s.length();
        vector<int> lps(n, 0);

        for(int i = 1; i < n; i++) {
            int prev_ind = lps[i -1];
            while(prev_ind > 0 && s[i] != s[prev_ind]) {
                prev_ind = lps[prev_ind - 1];
            }
            lps[i] = prev_ind + (s[i] == s[prev_ind]);
        }

        return lps;
    }
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> v;
        string s, p;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                s.push_back('c');
            }
            else if(nums[i] == nums[i - 1]) {
                s.push_back('b');
            }
            else {
                s.push_back('a');
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(pattern[i] == -1) {
                p.push_back('a');
            }
            else if(pattern[i] == 0) {
                p.push_back('b');
            }
            else {
                p.push_back('c');
            }
        }
        
        string str = p + "#" + s;
        vector<int> lps = kmp(str);
        
        int ans = 0;
        for(auto i : lps) ans += (i == m);
        
        return ans;
    }
};
