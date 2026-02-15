// K Most Frequent Elements

class Solution {

    public int[] topKFrequent(int[] nums, int k) {

        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Min Heap based on frequency
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {

            minHeap.offer(new int[]{entry.getKey(), entry.getValue()});

            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        // Step 3: Extract result
        int[] result = new int[k];
        int index = 0;

        while (!minHeap.isEmpty()) {
            result[index++] = minHeap.poll()[0];
        }

        return result;
    }
}

// ============================================================================

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> mp;
    for(auto i : arr) {
        mp[i]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto i : mp) {
        pq.push({i.second,i.first});
    }
    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

// T : O(N*LogN)
// S : O(N)
