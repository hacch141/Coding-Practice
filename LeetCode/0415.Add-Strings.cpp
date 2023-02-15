// 415. Add Strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int ptr1 = num1.size()-1;
        int ptr2 = num2.size()-1;

        while(ptr1>=0 && ptr2>=0) {
            ans += ((num1[ptr1]-'0' + num2[ptr2]-'0' + carry)%10)+'0';
            carry = (num1[ptr1]-'0' + num2[ptr2]-'0' + carry)/10;
            ptr1--;
            ptr2--;
        }
        while(ptr1>=0) {
            ans += ((num1[ptr1]-'0' + carry)%10)+'0';
            carry = (num1[ptr1]-'0' + carry)/10;
            ptr1--;
        }
        while(ptr2>=0) {
            ans += ((num2[ptr2]-'0' + carry)%10)+'0';
            carry = (num2[ptr2]-'0' + carry)/10;
            ptr2--;
        }
        if(carry) ans += carry+'0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
