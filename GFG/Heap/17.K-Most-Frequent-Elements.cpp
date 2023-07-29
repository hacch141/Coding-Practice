// K Most Frequent Elements

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
