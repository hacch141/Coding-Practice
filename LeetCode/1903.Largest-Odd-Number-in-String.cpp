// 1903. Largest Odd Number in String

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length(), ptr = n-1;
        while(ptr >= 0 && (num[ptr]-'0') % 2 == 0) ptr--;
        return num.substr(0,ptr+1);
    }
};
