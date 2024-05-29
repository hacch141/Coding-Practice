// 1404. Number of Steps to Reduce a Number in Binary Representation to One

class Solution {
public:
    int numSteps(string s) {
        int n = s.length(), steps = 0;
        for(int i = n - 1; i > 0; i--) {
            if(s[i] != '0') {
                int ptr = i;
                while(ptr >= 0 && s[ptr] == '1') {
                    s[ptr] = '0';
                    ptr--;
                }
                if(ptr >= 0) s[ptr] = '1';
                if(ptr < 0) steps++;
                steps++;
            }
            steps++;
        }
        return steps;
    }
};
