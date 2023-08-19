// Find the repeating and missing numbers

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();

    int XOR = 0;

    for(int i=0; i<n; i++) {
        XOR ^= a[i];
        XOR ^= (i+1);
    }

    int rightSetBit = 0;
    while(1) {
        if(XOR>>rightSetBit & 1) {
            break;
        }
        rightSetBit++;
    }

    int XOR1=0, XOR2=0;
    for(int i=0; i<n; i++) {
        if(a[i]>>rightSetBit & 1) {
            XOR1 ^= a[i];
        }
        else {
            XOR2 ^= a[i];
        }

        if((i+1)>>rightSetBit & 1) {
            XOR1 ^= (i+1);
        }
        else {
            XOR2 ^= (i+1);
        }
    }

    for(auto i : a) {
        if(i == XOR1) return {i,XOR2};
        if(i == XOR2) return {i,XOR1};
    }
    return {};
}

// T : O(N)
// S : O(1)


/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where N is the size of array 'A'
*/
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size(); // Size of array 'a'
    
    long long naturalSum = 1LL * n * (n + 1) / 2;
    long long squareSum = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    long long repeating, missing;
    
    for(int i = 0; i < n; ++i) {
        // Subtracting current element
        // from naturalSum
        naturalSum -= a[i];
        
        // Subtracting current element square
        // from squareSum
        squareSum -= 1LL * a[i] * a[i];
    }
    missing = (naturalSum + (squareSum / naturalSum)) / 2;
    repeating = (missing - naturalSum);
    
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}



/*
    Time Complexity: O( N )
    Space Complexity: O( N )

    where N is the size of array 'A'
*/
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size(); // Size of array 'a'
    
    vector<int> count(n + 1, 0); // 'count' array
    for(int i = 0; i < n; ++i) {
        // Incrementing the frequency of current element
        ++count[a[i]];
    }
    int missing, repeating;
    for(int i = 1; i <= n; ++i) {
        if(count[i] == 0) missing = i;
        else if(count[i] == 2) repeating = i;
    }
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}
