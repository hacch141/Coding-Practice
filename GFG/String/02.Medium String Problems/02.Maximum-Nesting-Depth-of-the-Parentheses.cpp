// Maximum Nesting Depth of the Parentheses

class Solution {
public:
    int maxDepth(string s) {
        int cntOpen = 0;
        int ans = INT_MIN;
        for(auto i : s) {
            if(i =='(') {
                cntOpen++;
            }
            else if(i == ')') {
                cntOpen--;
            }
            ans = max(ans,cntOpen);
        }
        return ans;
    }
};

// T : O(N)
// S : O(1)
