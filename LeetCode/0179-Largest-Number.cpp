// 179. Largest Number

class Solution {
public:
    static bool compare(string& s1, string& s2) {
        string t1 = s1 + s2, t2 = s2 + s1;
        if(t1 > t2) {
            return true;
        }
        return false;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i : nums) v.push_back(to_string(i));
        sort(v.begin(), v.end(), compare);
        string ans = "";
        for(auto s : v) ans += s;
        return ans[0] != '0' ? ans : "0";
    }
};
