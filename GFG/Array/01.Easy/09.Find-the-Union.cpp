// Find the Union

vector <int> sortedArray(vector<int>a, vector<int>b) {
    // Write your code here
    int i=0, j=0;
    int n1=a.size(), n2=b.size();
    vector<int> ans;

    while(i<n1 && j<n2) {
        if(a[i] <= b[j]) {
            if(ans.size() == 0 || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }
        else if(a[i] > b[j]) {
            if(ans.size() == 0 || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1) {
        if(ans.size() == 0 || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j<n2) {
        if(ans.size() == 0 || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}
// T : O(M+N)
// S : O(1)
