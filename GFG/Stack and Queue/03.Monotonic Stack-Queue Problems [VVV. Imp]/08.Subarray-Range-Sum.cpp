// Subarray Range Sum

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
