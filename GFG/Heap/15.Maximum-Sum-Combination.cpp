// Maximum Sum Combination

class Solution {

    public ArrayList<Integer> topKSumPairs(int[] A, int[] B, int k) {

        int n = A.length;

        Arrays.sort(A);
        Arrays.sort(B);

        // Max Heap (based on sum)
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));

        Set<String> visited = new HashSet<>();

        // Push largest pair
        maxHeap.offer(new int[]{A[n-1] + B[n-1], n-1, n-1});
        visited.add((n-1) + "#" + (n-1));

        ArrayList<Integer> result = new ArrayList<>();

        while (k-- > 0 && !maxHeap.isEmpty()) {

            int[] curr = maxHeap.poll();

            int sum = curr[0];
            int i = curr[1];
            int j = curr[2];

            result.add(sum);

            // Push (i-1, j)
            if (i - 1 >= 0 && !visited.contains((i-1) + "#" + j)) {
                maxHeap.offer(new int[]{A[i-1] + B[j], i-1, j});
                visited.add((i-1) + "#" + j);
            }

            // Push (i, j-1)
            if (j - 1 >= 0 && !visited.contains(i + "#" + (j-1))) {
                maxHeap.offer(new int[]{A[i] + B[j-1], i, j-1});
                visited.add(i + "#" + (j-1));
            }
        }

        return result;
    }
}

// =====================================================================

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        pq.push({A[N-1] + B[N-1] , {N-1, N-1}});
        st.insert({N-1 , N-1});
        
        vector<int> ans;
        while(K--) {
            auto it = pq.top();
            pq.pop();
            
            int ptrA = it.second.first;
            int ptrB = it.second.second;
            int sum = it.first;
            
            ans.push_back(sum);
            
            if(ptrA > 0 && !st.count({ptrA-1 , ptrB})) {
                pq.push({A[ptrA-1] + B[ptrB] , {ptrA-1 , ptrB}});
                st.insert({ptrA-1 , ptrB});
            }
            if(ptrB > 0 && !st.count({ptrA , ptrB-1})) {
                pq.push({A[ptrA] + B[ptrB-1] , {ptrA , ptrB-1}});
                st.insert({ptrA , ptrB-1});
            }
        }
        
        return ans;
    }
};

// T : O(N * log(N)) + O(K * log(N))
// S : O(N)
