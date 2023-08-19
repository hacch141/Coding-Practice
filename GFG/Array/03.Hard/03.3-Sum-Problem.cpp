// 3-Sum Problem

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        int low = i+1;
        int high = n-1;
        int target = -arr[i];

        if(i>0 && arr[i]==arr[i-1]) continue;

        while(low < high) {
            int sum = arr[low] + arr[high];
            if(sum == target) {
                ans.push_back({arr[i],arr[low],arr[high]});
                low++;
                high--;
                while(low<n && arr[low]==arr[low-1]) low++;
                while(high>=0 && arr[high]==arr[high+1]) high--;
            }
            else if(sum < target) {
                low++;
            }
            else {
                high--;
            }
        }
    }
    return ans;
}
// T : O(N*Log N + N^2)
// S : O(1)


vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;
    for (int i=0; i<n; i++) {
        set<int> hashset;
        for (int j=i+1; j<n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// T : O(N^2 * Log (Triplet))
// S : O(N + Triplet)



vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// T : O(N^3 * Log (triplet))
// S : O(Triplets)
