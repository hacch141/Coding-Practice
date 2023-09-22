// Maximum Sum Combination

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
