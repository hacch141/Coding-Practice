// 1980. Find Unique Binary String

class Solution {
public:
    string rec(int ind, int n, string& curr, char prev, set<string>& st) {
        if(ind == n) {
            if(!st.count(curr)) return curr;
            return "";
        }
        
        curr.push_back('1');
        string ans = rec(ind + 1, n, curr, '1', st);
        if(ans.length() > 0) return ans;
        curr.pop_back();

        curr.push_back('0');
        ans = rec(ind + 1, n, curr, '0', st);
        curr.pop_back();

        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        set<string> st;
        for(auto &s : nums) {
            st.insert(s);
        }
        string curr = "";
        return rec(0, n, curr, 'a', st);
    }
};
