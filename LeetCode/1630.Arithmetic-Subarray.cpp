// 1630. Arithmetic Subarrays

class Solution {
public:

    bool isValid(vector<int> arr) {
        int n = arr.size();
        if(n==0 || n==1 || n==2) return true;

        sort(arr.begin(),arr.end());
        int d = arr[1] - arr[0];

        for(int i=0; i<n-1; i++) {
            if(arr[i+1] - arr[i] != d) {
                return false;
            }
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        vector<bool> ans;

        for(int i=0; i<l.size(); i++) {
            int start = l[i];
            int end = r[i];

            vector<int> arr;
            for(int ind=start; ind<=end; ind++) {
                arr.push_back(nums[ind]);
            }

            if(isValid(arr)) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};



class Solution {
public:

    bool isValid(vector<int>& arr) {
        int n = arr.size();
        if(n==0 || n==1 || n==2) return true;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]);
            st.insert(arr[i]);
        }

        if((maxi-mini) % (n-1) != 0) return false;
        int d = (maxi-mini)/(n-1);

        int num = mini;
        while(num < maxi) {
            num += d;
            if(!st.count(num)) return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        vector<bool> ans;

        for(int i=0; i<l.size(); i++) {
            int start = l[i];
            int end = r[i];

            vector<int> arr;
            for(int ind=start; ind<=end; ind++) {
                arr.push_back(nums[ind]);
            }

            if(isValid(arr)) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
