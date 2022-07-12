// Chef and his Apps
// Problem Code:CHEFAPPS

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int S, X, Y, Z;
	    cin >> S >> X >> Y >> Z;
	    int max1 = max(X, Y);
	    int min1 = min(X, Y);
	    int total = X+Y+Z;
	    if(total <= S) {
	        cout << 0 << endl;
	    }
	    else if(total-max1 <= S) {
	        cout << 1 << endl;
	    }
	    else {
	        cout << 2 << endl;
	    }
	}
	return 0;
}
