// 1441. Build an Array With Stack Operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();

        vector<string> ans;
        int cnt = 1;
        for(int i=0; i<len; i++) {
            while(cnt != target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                cnt++;
            }
            ans.push_back("Push");
            cnt++;
        }

        return ans;
    }
};
