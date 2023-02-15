// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        int i = n-1;
        vector<int> ans;

        while(i>=0 && carry) {
            ans.push_back((digits[i]+carry)%10);
            carry = (digits[i]+carry)/10;
            i--;
        }
        while(i>=0) {
            ans.push_back(digits[i]);
            i--;
        }
        if(carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
