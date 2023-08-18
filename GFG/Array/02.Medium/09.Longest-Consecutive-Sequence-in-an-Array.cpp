// Longest Consecutive Sequence in an Array

int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    unordered_map<int,int> mp;
    for(auto i : a) {
        mp[i]++;
    }

    int ans = 0;
    for(auto i : a) {
        if(mp.find(i-1) == mp.end()) {
            int num = i;
            int cnt = 0;
            while(mp.find(num) != mp.end()) {
                cnt++;
                num++;
            }
            ans = max(ans,cnt);
        }
    }
    
    return ans;
}
// T : O(N)
// S : O(N)


int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    sort(a.begin(),a.end());

    int cnt = 1;
    int ans = 1;
    for(int i=1; i<n; i++) {
        if(a[i] == a[i-1]) continue;
        if(a[i] == 1+a[i-1]) {
            cnt++;
            ans = max(ans,cnt);
        }
        else {
            cnt = 1;
        }
    }

    return ans;
}
// T : O(N * Log N)
// S : O(1)
