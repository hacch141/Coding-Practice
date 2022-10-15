// 415. Add Strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        long add = 0;
        int l1 = num1.length()-1;
        int l2 = num2.length()-1;
        while(l1 >= 0 || l2 >= 0 || carry) {
            add = 0;
            if(l1 >= 0) {
                add += num1[l1]-'0';
                l1--;
            } 
            if(l2 >= 0) {
                add += num2[l2]-'0';
                l2--;
            } 
            add += carry;
            carry = add/10;
            add = add%10;
            ans += (add)+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
