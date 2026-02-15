// Sort K Sorted Arrays

class Solution {

    public void sortKSortedArray(int[] arr, int k) {

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        int n = arr.length;
        int index = 0;

        // 1️⃣ Insert first k+1 elements
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.offer(arr[i]);
        }

        // 2️⃣ Process remaining elements
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.poll();
            minHeap.offer(arr[i]);
        }

        // 3️⃣ Empty the heap
        while (!minHeap.isEmpty()) {
            arr[index++] = minHeap.poll();
        }
    }
}

// ================================================================================

// Merge K Sorted Arrays
class Solution {

    public List<Integer> mergeKSortedArrays(List<List<Integer>> kArrays) {

        int k = kArrays.size();

        // Min Heap based on value (a[0])
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        // Insert first element of each array
        for (int i = 0; i < k; i++) {
            if (!kArrays.get(i).isEmpty()) {
                pq.offer(new int[]{ 
                        kArrays.get(i).get(0),  // value
                        i,                      // array index
                        0                       // element index
                });
            }
        }

        List<Integer> result = new ArrayList<>();

        while (!pq.isEmpty()) {

            int[] curr = pq.poll();
            int value = curr[0];
            int arrayIndex = curr[1];
            int elementIndex = curr[2];

            result.add(value);

            int nextIndex = elementIndex + 1;

            // Push next element from same array
            if (nextIndex < kArrays.get(arrayIndex).size()) {
                pq.offer(new int[]{
                        kArrays.get(arrayIndex).get(nextIndex),
                        arrayIndex,
                        nextIndex
                });
            }
        }

        return result;
    }
}

// ===================================================================================
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    int n = kArrays.size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    for(int i=0; i<n; i++) {
        pq.push({kArrays[i][0],{i,0}});
    }

    vector<int> ans;
    while(!pq.empty()) {
        int ele = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        ans.push_back(ele);
        y++;
        if(y < kArrays[x].size()) {
            pq.push({kArrays[x][y],{x,y}});
        }
    }

    return ans;
}

// T : O(N*K*LogK)
// S : O(K)
