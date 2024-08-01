// 2678. Number of Senior Citizens
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto s : details) {
            string tmp = s.substr(11, 2);
            ans += (stoi(tmp) > 60);
        }
        return ans;
    }
};
