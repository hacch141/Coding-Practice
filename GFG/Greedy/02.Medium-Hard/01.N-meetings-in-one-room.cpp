// N meetings in one room

static bool compare(pair<int,int>& p1, pair<int,int>& p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int,int>> v;
    int n = start.size();
    for(int i=0; i<n; i++) {
        v.push_back({start[i],end[i]});
    }

    sort(v.begin(),v.end(),compare);

    int ans = 0;
    for(int i=0; i<n; i++) {
        int end = v[i].second;
        while(i+1<n && v[i+1].first <= end) {
            i++;
        }
        ans++;
    }
    return ans;
}

// T : O(N LogN)
// S : O(N)
