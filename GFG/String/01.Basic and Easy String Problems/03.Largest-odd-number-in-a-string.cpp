// Largest odd number in a string

class Solution {
public:
    string largestOddNumber(string num) {
        int right = num.size() - 1;
        while(right >= 0 && (num[right]-'0') % 2 != 1) {
            right--;
        }

        if(right == -1) return "";
        return num.substr(0,right+1);
    }
};

// T : O(N)
// S : O(1)
