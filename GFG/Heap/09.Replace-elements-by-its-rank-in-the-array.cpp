// Replace elements by its rank in the array

class Solution {

    public int[] replaceWithRank(int[] arr) {

        int n = arr.length;

        // Min Heap
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Insert all elements
        for (int num : arr) {
            pq.offer(num);
        }

        // OR
        // int[] sorted = arr.clone();
        // Arrays.sort(sorted);

        // Map to store value → rank
        Map<Integer, Integer> rankMap = new HashMap<>();

        int rank = 1;

        // Extract in sorted order
        while (!pq.isEmpty()) {

            int val = pq.poll();

            if (!rankMap.containsKey(val)) {
                rankMap.put(val, rank++);
            }
        }

        // Replace original values
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            result[i] = rankMap.get(arr[i]);
        }

        return result;
    }
}

// ======================================================================

vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto i : arr) {
        pq.push(i);
    }

    unordered_map<int,int> mp;
    int rank = 1;
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if(mp.find(a) == mp.end()) {
            mp[a] = rank;
            rank++;
        }
    }

    vector<int> ans;
    for(auto i : arr) {
        ans.push_back(mp[i]);
    }
    return ans;
}

// T : O(N * LogN)
// S : O(N)
