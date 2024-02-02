// 1291. Sequential Digits

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        int num;
        for(int len = 2; len <= 9; len++) {
            for(int i = 0; i <= 9 - len; i++) {
                string curr = s.substr(i, len);
                num = stoi(curr);
                if(low <= num && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};
