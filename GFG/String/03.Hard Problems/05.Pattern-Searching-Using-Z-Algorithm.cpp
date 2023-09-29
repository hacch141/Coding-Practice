// Pattern Searching Using Z-Algorithm

vector<int> search(string s, string pattern) {
    // Write Your Code Here
    int l=0, r=0;
    int m = pattern.length();

    string c = pattern + '$' + s;
    int k = c.length();

    vector<int> ans;

    vector<int> zarr(k);
    zarr[0] = 0;

    for(int i=1; i<k; i++) {
        if(i>r) {
            l = i;
            r = i;
            while(r<k && c[r-l] == c[r]) {
                r++;
            }
            zarr[i] = r - l;
            r--;
            if(zarr[i] == m) {
                ans.push_back(i-m);
            }
        }
        else {
            int pos = i - l;
            if(zarr[pos] + i <= r) {
                zarr[i] = zarr[pos];
                if(zarr[i] == m) {
                    ans.push_back(i-m);
                }
            }
            else {
                l = i;
                while(r<k && c[r-l] == c[r]) {
                    r++;
                }
                zarr[i] = r - l;
                r--;
                if(zarr[i] == m) {
                    ans.push_back(i-m);
                }
            }
        }
    }

    return ans;
}

// T : O(M+N)
// S : O(K)
