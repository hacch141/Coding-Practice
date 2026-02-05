// Roman Number to Integer

class Solution {
    public int romanToInt(String s) {
        Map<String,Integer> mp = new HashMap<>();
        mp.put("I", 1);
        mp.put("V", 5);
        mp.put("X", 10);
        mp.put("L", 50);
        mp.put("C", 100);
        mp.put("D", 500);
        mp.put("M", 1000);

        int n = s.length();
        int ans = mp.get(s.substring(n - 1, n));
        for (int i = 0; i < n - 1; i++) {
            if (mp.get(s.substring(i, i + 1)) < mp.get(s.substring(i + 1, i + 2))) {
                ans -= mp.get(s.substring(i, i + 1));
            }
            else {
                ans += mp.get(s.substring(i, i + 1));
            }
        }

        return ans;
    }
}

// ===================================================================================

int romanToInt(string s) {
    // Write your code here
    unordered_map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    int n = s.length();
    ans = mp[s[n-1]];

    for(int i=n-2; i>=0; i--) {
        if(mp[s[i]] < mp[s[i+1]]) {
            ans -= mp[s[i]];
        }
        else {
            ans += mp[s[i]];
        }
    }
    return ans;
}
// T : O(n)
// S : O(1)



/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is length of the string.
*/

int romanToIntHelper(string s, map<string, int> &conv)
{
    // If single character, return the integer value of that character.
    if (s.size() <= 1)
    {
        return conv[s];
    }
    // Take first 2 characters.
    string first_two = s.substr(0, 2);

    // If the first 2 characters are in the map, add their value and check rest of the string.
    if (conv.count(first_two))
    {
        return conv[first_two] + romanToIntHelper(s.substr(2, s.size() - 2), conv);
    }
    else
    {
        // otherwise take one character and check its value.
        return conv[s.substr(0, 1)] + romanToIntHelper(s.substr(1, s.size() - 1), conv);
    }
}

int romanToInt(string s)
{
    map<string, int> conv{
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1},
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
        {"", 0}};
    return romanToIntHelper(s, conv);
}
