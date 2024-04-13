// 85. Maximal Rectangle

class Solution {
public:

    int solve(vector<int>& height) {
        int n = height.size();
        vector<int> leftSmall(n), rightSmall(n);

        // find rightSmall
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] < height[st.top()]) {
                rightSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            rightSmall[st.top()] = n;
            st.pop();
        }

        // find leftSmall
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && height[i] < height[st.top()]) {
                leftSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            leftSmall[st.top()] = -1;
            st.pop();
        }

        // find Max Area
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, (height[i]) * (rightSmall[i] - leftSmall[i] - 1));
        }
        return mxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[i][j] = 1;
                    if(i > 0) heights[i][j] += heights[i - 1][j];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(heights[i]));
        }
        return ans;
    }
};
