// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        nums.resize(2*n);
        for(int i=0; i<n; i++) {
            nums[n+i] = nums[i];
        }
        int N = nums.size();
        st.push(nums[N-1]);
        ans.push_back(-1);
        
        for(int i=N-2; i>=0; i--) {
            while(st.empty() == false && st.top() <= nums[i]) {
                st.pop();
            }
            if(st.empty() == false) {
                ans.push_back(st.top());
            }
            else {
                ans.push_back(-1);
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        ans.resize(n);
        return ans;
    }
  
//   vector<int> nextGreaterElements(vector<int>& nums) {   // 2nd Method
//         vector<int> ans;
//         vector<int> temp;
//         for(int i=0; i<nums.size(); i++) {
//             temp.push_back(nums[i]);
//         }
//         for(int i=0; i<nums.size(); i++) {
//             temp.push_back(nums[i]);
//         }
        
//         stack<int> st;
//         int n = temp.size();
//         st.push(temp[n-1]);
//         ans.push_back(-1);
        
//         for(int i=n-2; i>=0; i--) {
//             while(st.empty() == false && st.top() <= temp[i]) {
//                 st.pop();
//             }
//             if(st.empty() == false) {
//                 ans.push_back(st.top());
//             }
//             else {
//                 ans.push_back(-1);
//             }
//             st.push(temp[i]);
//         }
//         for(auto i : ans) {
//             cout << i << " ";
//         }
//         reverse(ans.begin(),ans.end());
//         ans.resize(nums.size());
//         return ans;
//     }
};
