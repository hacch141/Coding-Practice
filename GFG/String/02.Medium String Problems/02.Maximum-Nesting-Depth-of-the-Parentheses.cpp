// Maximum Nesting Depth of the Parentheses

class Solution {
    public int maxDepth(String s) {
        int mx = 0;
        int open = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                open++;
            }
            else if (ch == ')') {
                open--;
            }
            mx = Math.max(mx, open);
        }

        return mx;
    }
}

// ==================================================

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
