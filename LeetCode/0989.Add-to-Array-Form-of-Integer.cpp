// 989. Add to Array-Form of Integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n-1;
        int carry = 0;
        vector<int> ans;

        while(i>=0 && k>0) {
            ans.push_back((num[i] + k%10 + carry)%10);
            carry = (num[i] + k%10 + carry)/10;
            k = k/10;
            i--;
        }
        while(k>0) {
            ans.push_back((k%10 + carry)%10);
            carry = (k%10 + carry)/10;
            k = k/10;
        }
        while(i>=0) {
            ans.push_back((num[i] + carry)%10);
            carry = (num[i] + carry)/10;
            i--;
        }
        if(carry>0) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
