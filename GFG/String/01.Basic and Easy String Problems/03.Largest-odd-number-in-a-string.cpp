// Largest odd number in a string

class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        int lastIndex = -1;
        for (int i = n - 1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 == 1) {
                lastIndex = i;
                break;
            }
        }

        if (lastIndex == -1) return "";

        return num.substring(0, lastIndex + 1);
    }
}

// ==================================================================

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
