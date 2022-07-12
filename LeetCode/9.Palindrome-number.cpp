// 9. Palindrome Number

class Solution {
public:
    bool isPalindrome(int x) {
        bool ans;
        int num = x;
        if(x < 0) return false;
        if(x == 0) return true;
        long long rev = 0;
        int rem = 0;
        while(x>0) {
            rem = x%10;
            rev = rev*10 + rem;
            x = x/10;
        }
        if(num == rev) {
            ans = true;
        }
        else {
            ans = false; 
        }
        return ans;
    }
};
