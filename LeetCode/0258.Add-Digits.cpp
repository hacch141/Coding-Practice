// 258. Add Digits

class Solution {
public:
    int addDigits(int num) {
        int a = 0;

        while(num/10 > 0) {
            a = 0;

            while(num > 0) {
                a += num%10;
                num /= 10;
            }

            num = a;
        }

        return num;
    }
};
