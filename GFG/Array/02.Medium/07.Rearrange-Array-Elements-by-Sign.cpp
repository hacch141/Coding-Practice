// Rearrange Array Elements by Sign

vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    int pos = 0;
    int neg = 1;
    vector<int> ans(n);

    for(auto i : a) {
        if(i > 0) {
            ans[pos] = i;
            pos += 2;
        }
        else {
            ans[neg] = i;
            neg += 2;
        }
    }

    return ans;
}
// T : O(N)
// S : O(N)


/*
    Time Complexity: O( N )
    Space Complexity: O( N )

    Where 'N' is the length of the array 'A'.
*/

vector<int> alternateNumbers(vector<int>&a) {

    int n = a.size();

    // Initialize two empty arrays, 'pos' and 'neg'.
    vector<int>pos, neg;

    // Push positive elements to 'pos' array and
    // push negative elements to 'neg' array.
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }

    int i = 0, j = 0, k = 0;

    // Update the array 'a' with alternate postive and
    // negative numbers.
    while (i < pos.size() and j < neg.size()) {
        a[k] = pos[i];
        k++, i++;
        a[k] = neg[j];
        k++, j++;
    }

    // Return the answer 'a' here.
    return a;
}
