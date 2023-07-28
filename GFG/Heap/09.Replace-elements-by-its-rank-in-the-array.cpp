// Replace elements by its rank in the array

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
