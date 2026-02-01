// Minimum Multiplications to reach End

class Solution {
    long MOD = (long)1e5;
    int minimumMultiplications(int[] arr, int start, int end) {
        boolean[] vis = new boolean[100001];
        Queue<Integer> q = new LinkedList<>();

        q.add(start);
        vis[start] = true;

        int lvl = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int curr = q.poll();
                if (curr == end) return lvl;
                for (int num : arr) {
                    int next = (int)((1L * curr * num) % MOD);
                    if (!vis[next]) {
                        vis[next] = true;
                        q.add(next);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
}

// ==================================================================

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> mult(100000,1e9);
        mult[start] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,start});
        
        while(!q.empty()) {
            int u = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            for(auto i : arr) {
                int curr = (u*i)%100000;
                if(steps + 1 < mult[curr]) {
                    if(curr == end) return steps + 1;
                    mult[curr] = steps + 1;
                    q.push({steps+1,curr});
                }
            }
        }
        
        return mult[end] != 1e9 ? mult[end] : -1;
    }
};

// T : O(100000 * N) N = size of arr
// S : O(100000 * N) N = size of arr
