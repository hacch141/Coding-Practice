// Majority Element > (N/2)

int majorityElement(vector<int> v) {
    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
// T : O(N)
// S : O(1)


/*
	Time Complexity: O( N )
	Space Complexity: O( 1 )

	where N is the number of elements
	of the array.
*/
#include <unordered_map>
int majorityElement(vector<int> v) {
	// n is the number of elements
	// in the array
	int n = v.size();

	// Hashmap to store key-value pair
	unordered_map<int, int> freq;
	for(int i = 0; i < n; ++i) {
		if(freq.count(v[i])) {
			// v[i] exists
			// Only increase the frequency
			++freq[v[i]];
		}
		else {
			// Doesn't exist
			freq[v[i]] = 1;
		}
	}

	for(auto& p : freq) {
		int value = p.first, cnt = p.second;
		// value's frequency in the array 
		// is cnt

		if(cnt > n / 2) {
			return value;
		}
	}
}
