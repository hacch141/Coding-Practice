// Move Zero's to End

vector<int> moveZeros(int n, vector<int> a) {
    int j = 0;
    // Move all the nonzero elements advance.
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            a[j++] = a[i];
        }
    }

    // Setting up the rest elements as a zero.
    while(j<n) {
        a[j] = 0;
    }
    return a;
}

// T : O(N)
// S : O(1)
