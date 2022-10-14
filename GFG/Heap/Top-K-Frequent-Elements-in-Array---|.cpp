//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   1st Method
      static bool compare(pair<int,int> p1, pair<int,int> p2) {
        if(p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
  
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(mp.begin(), mp.end());
        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }

  
//   2nd Method
    struct compare {
        bool operator()(pair<int,int> p1, pair<int,int> p2) {
            if(p1.second == p2.second) {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        }
    };
  
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(mp.begin(), mp.end());
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
