// Integer To Roman Numeral

class Solution {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D",  "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < values.length; ++i) {
            if (num == 0)
                break;
            while (num >= values[i]) {
                sb.append(symbols[i]);
                num -= values[i];
            }
        }

        return sb.toString();        
    }
}

// ===============================================================================================

class Solution {
public:
    string intToRoman(int num) {

        string m[] = { "", "M", "MM", "MMM" };
        string c[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        string x[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        string i[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

        // Converting diffrent places digits into roman.
        string thousands = m[num / 1000];
        string hundereds = c[(num % 1000) / 100];
        string tens = x[(num % 100) / 10];
        string ones = i[num % 10];

        string ans = thousands + hundereds + tens + ones;

        return ans;
    }
};
// T : O(1)
// S : O(1)



#include <bits/stdc++.h> 

string intToRoman(int num) {
    // Write your code here.

    vector<int> values =     { 1000, 900 , 500 , 400  , 100 , 90   , 50  , 40   , 10  , 9    , 5   , 4    , 1   };
    vector<string> symball = { "M" , "CM", "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I" };

    string ans = "";
    int ptr = 0;
    while(num) {
        while(values[ptr] > num) {
            ptr++;
        }
        ans += symball[ptr];
        num -= values[ptr];
    }

    return ans;
}
// T : O()
// S : O(1)
