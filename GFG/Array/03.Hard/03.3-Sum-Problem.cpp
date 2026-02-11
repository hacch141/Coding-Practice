// 3-Sum Problem

class Solution {
    public List<List<Integer>> triplet(int n, int[] arr) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];

                if (sum == 0) {
                    ans.add(Arrays.asList(arr[i], arr[low], arr[high]));

                    low++;
                    high--;

                    while (low < high && arr[low] == arr[low - 1]) low++;
                    while (low < high && arr[high] == arr[high + 1]) high--;
                }
                else if (sum > 0) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }

        return ans;
    }
}

class Solution {
    public List<List<Integer>> threeSum(int[] arr) {
        int n = arr.length;
        Set<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> map = new HashMap<>();

            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];

                if (map.containsKey(-sum)) {
                    List<Integer> temp = Arrays.asList(arr[i], arr[j], arr[map.get(-sum)]);
                    Collections.sort(temp);
                    set.add(temp);
                }

                map.put(arr[j], j);
            }
        }

        return new ArrayList<>(set);
    }
}

// ==================================================================================

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0; i<n; i++) {
        if(i>0 && arr[i]==arr[i-1]) continue;
        int low = i+1;
        int high = n-1;
        while(low < high) {
            int sum = arr[i] + arr[low] + arr[high];
            if(sum == 0) {
                ans.push_back({arr[i],arr[low],arr[high]});
                low++;
                high--;
                while(low<high && arr[low]==arr[low-1]) low++;
                while(low<high && arr[high]==arr[high+1]) high--;
            }
            else if(sum > 0) {
                high--;
            }
            else {
                low++;
            }
        }
    }

    return ans;
}
// T : O(N*Log N + N^2)
// S : O(1)


vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        unordered_map<int,int> mp;
        for(int j=i+1; j<n; j++) {
            int sum = arr[i] + arr[j];
            if(mp.find(-sum) != mp.end()) {
                vector<int> v = {arr[i],arr[j],arr[mp[-sum]]};
                sort(v.begin(),v.end());
                st.insert(v);
            }
            mp[arr[j]] = j;
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());

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
