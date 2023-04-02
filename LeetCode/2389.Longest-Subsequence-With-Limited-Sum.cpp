// 2389. Longest Subsequence With Limited Sum

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = queries.size();
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }

        vector<int> ans;
        for(int i=0; i<m; i++) {
            int low = 0;
            int high = n-1;
            bool flag = false;
            while(low<=high) {
                int mid = (high-low)/2 + low;
                if(nums[mid] == queries[i]) {
                    ans.push_back(mid+1);
                    flag = true;
                    break;
                }
                else if(nums[mid] > queries[i]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            if(!flag) ans.push_back(low);
        }
        return ans;
    }
};
