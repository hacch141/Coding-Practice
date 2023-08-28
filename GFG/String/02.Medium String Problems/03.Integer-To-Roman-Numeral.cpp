// Integer To Roman Numeral

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
