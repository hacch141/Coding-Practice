// 4-Sum Problem

import java.util.*;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        int n = nums.length;
        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int low = j + 1;
                int high = n - 1;

                while (low < high) {

                    long sum = (long) nums[i] + nums[j] + nums[low] + nums[high];

                    if (sum == target) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[low], nums[high]));

                        low++;
                        high--;

                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    }
                    else if (sum < target) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }

        return ans;
    }
}

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        int n = nums.length;
        Set<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                Map<Long, Integer> map = new HashMap<>();

                for (int k = j + 1; k < n; k++) {

                    long sum = (long) nums[i] + nums[j] + nums[k];
                    long rem = (long) target - sum;

                    if (map.containsKey(rem)) {
                        List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], nums[map.get(rem)]);
                        Collections.sort(temp);
                        set.add(temp);
                    }
                    map.put((long) nums[k], k);
                }
            }
        }

        return new ArrayList<>(set);
    }
}

// ==========================================================================================

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int low = j+1;
            int high = n-1;
            while(low < high) {
                int sum = nums[i] + nums[j] + nums[low] + nums[high];
                if(sum == target) {
                    ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
                else if(sum < target) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }
    }
    return ans;
}
// T : O( (N * Log N) + (N^3) )
// S : O(quadruplets)


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            unordered_map<int,int> mp;
            for(int k=j+1; k<n; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                int rem = target - sum;
                if(mp.find(rem) != mp.end()) {
                    vector<int> v = {nums[i],nums[j],nums[k],nums[mp[rem]]};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
                else {
                    mp[nums[k]] = k;
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// T : O(N^3 * Log quadruplets)
// S : O(quadruplets)


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// T : O(N^4 * Log quadruplets)
// S : O(quadruplets)
