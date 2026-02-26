// Subarray Range Sum

class Solution {
    private long getSumMin(int[] arr, int n) {
        Stack<Integer> st = new Stack<>();

        int[] pre = new int[n];
        int[] next = new int[n];

        for (int i = 0; i < n; i++) {
            pre[i] = i;
            next[i] = n - i - 1;
        }

        // Next Smaller (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[i] < arr[st.peek()]) {
                int idx = st.pop();
                next[idx] = i - idx - 1;
            }
            st.push(i);
        }
        st.clear();

        // Previous Smaller (less or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[i] <= arr[st.peek()]) {
                int idx = st.pop();
                pre[idx] = idx - i - 1;
            }
            st.push(i);
        }
        st.clear();

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long) arr[i] * (pre[i] + 1) * (next[i] + 1);
        }

        return sum;
    }

    private long getSumMax(int[] arr, int n) {
        Stack<Integer> st = new Stack<>();

        int[] pre = new int[n];
        int[] next = new int[n];

        for (int i = 0; i < n; i++) {
            pre[i] = i;
            next[i] = n - i - 1;
        }

        // Next Greater (strictly greater)
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[i] > arr[st.peek()]) {
                int idx = st.pop();
                next[idx] = i - idx - 1;
            }
            st.push(i);
        }
        st.clear();

        // Previous Greater (greater or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[i] >= arr[st.peek()]) {
                int idx = st.pop();
                pre[idx] = idx - i - 1;
            }
            st.push(i);
        }
        st.clear();

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long) arr[i] * (pre[i] + 1) * (next[i] + 1);
        }

        return sum;
    }

    public long subArrayRanges(int[] arr) {
        int n = arr.length;
        return getSumMax(arr, n) - getSumMin(arr, n);
    }
}

// ==================================================================================================

int rangeSum(vector<int>&nums){
    // Write your code here.
    int n = nums.size(); 
    vector<int> next1(n), prev1(n); // for finding MINI
    vector<int> next2(n), prev2(n); // for finding MAXI
    stack<int> st1, st2;

    for(int i=0; i<n; i++) {
        prev1[i] = i;
        next1[i] = n-1-i;
        prev2[i] = i;
        next2[i] = n-1-i;
    }

    // next smaller ele
    for(int i=0; i<n; i++) {
        while(!st1.empty() && nums[i] < nums[st1.top()]) {
            next1[st1.top()] = i - st1.top() - 1;
            st1.pop();
        }
        st1.push(i);
    }

    for(int i=n-1; i>=0; i--) {
        while(!st2.empty() && nums[i] <= nums[st2.top()]) {
            prev1[st2.top()] = st2.top() - i - 1;
            st2.pop();
        }
        st2.push(i);
    }

    // empty the both stack for reuse
    while(!st1.empty()) st1.pop();
    while(!st2.empty()) st2.pop();


    // next greater ele
    for(int i=0; i<n; i++) {
        while(!st1.empty() && nums[i] > nums[st1.top()]) {
            next2[st1.top()] = i - st1.top() - 1;
            st1.pop();
        }
        st1.push(i);
    }

    for(int i=n-1; i>=0; i--) {
        while(!st2.empty() && nums[i] >= nums[st2.top()]) {
            prev2[st2.top()] = st2.top() - i - 1;
            st2.pop();
        }
        st2.push(i);
    }


    int ans = 0;
    for(int i=0; i<n; i++) {
        // add all maxi range to ans
        ans += (nums[i] * (1 + next2[i]) * (1 + prev2[i]));

        // remove all mini range to ans 
        ans -= (nums[i] * (1 + next1[i]) * (1 + prev1[i]));
        
        // to get the diff of each range (maxi - mini)
    }

    return ans;
}

// T : O(N)
// S : O(N)
