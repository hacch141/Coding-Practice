// Remove outermost Paranthesis

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for(auto i : s) {
            if(i == '(') {
                cnt++;
            }
            if(cnt > 1) {
                ans += i;
            }
            if(i == ')') {
                cnt--;
            }
        }
        return ans;
    }
};

// T : O(N)
// S : O(N)


int maxDepth(string s) {
	// Write your code here.
	int depth = 0;
	int ans = INT_MIN;
	for(auto i : s) {
		if(i == '(') {
			depth++;
		}
		else if(i == ')') {
			depth--;
		}
		ans = max(ans,depth);
	}
	return ans;
}
