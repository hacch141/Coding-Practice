// 496. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        stack<int> st;
        int n1 = nums1.size();
        int n2 = nums2.size();
        st.push(nums2[n2-1]);
        mp[nums2[n2-1]] = -1;
        
        for(int i=n2-1; i>=0; i--) {
            while(st.empty() == false && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.empty() == false) {
                mp[nums2[i]] = st.top();
            }
            else {
                mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        
        for(int i=0; i<n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
