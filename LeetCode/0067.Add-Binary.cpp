// 67. Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n1 = a.length();
        int n2 = b.length();
        int ptr1 = n1-1;
        int ptr2 = n2-1;
        int carry = 0;

        while(ptr1>=0 && ptr2>=0) {
            if((a[ptr1]=='1'&&b[ptr2]=='0') || (a[ptr1]=='0'&&b[ptr2]=='1')) {
                if(carry) {
                    ans += '0';
                    carry = 1;
                }
                else {
                    ans += '1';
                }
            }
            else if(a[ptr1]=='0'&&b[ptr2]=='0') {
                if(carry) {
                    ans += '1';
                    carry = 0;
                }
                else {
                    ans += '0';
                }
            }
            else {
                if(carry) {
                    ans += '1';
                    carry = 1;
                }
                else {
                    ans += '0';
                    carry = 1;
                }
            }
            ptr1--;
            ptr2--;
        }
        while(ptr1>=0) {
            if(a[ptr1]=='0') {
                if(carry) {
                    ans += '1';
                    carry = 0;
                }
                else {
                    ans += '0';
                }
            }
            else {
                if(carry) {
                    ans += '0';
                    carry = 1;
                }
                else {
                    ans += '1';
                }
            }
            ptr1--;
        }
        while(ptr2>=0) {
            if(b[ptr2]=='0') {
                if(carry) {
                    ans += '1';
                    carry = 0;
                }
                else {
                    ans += '0';
                }
            }
            else {
                if(carry) {
                    ans += '0';
                    carry = 1;
                }
                else {
                    ans += '1';
                }
            }
            ptr2--;
        }
        if(carry) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
